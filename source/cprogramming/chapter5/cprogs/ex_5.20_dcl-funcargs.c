/**
 * Exercise 5-20. Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
 **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 500
#define MAXOUTPUT 5000 // value must be <= 1.8 million to prevent a buffer overflow attack (when x = 99,999, y = 1,800,032 in y = 18x + 50)
#define BUFSIZE MAXTOKEN * 2 // * 2 because system might need to push back two tokens worth of chars
#define NUMOFSTORAGECLASSES 5
#define NUMOFTYPEQUALIFIERS 4
#define NUMOFTYPESPECIFIERS 11

enum tokentype { VARIABLE, BRACKETS, STORAGECLASS, TYPEQUALIFIER, TYPESPECIFIER };
enum returnstatus { OK, ERROR };
enum boolean { FALSE, TRUE };

int processDeclaration(char *declaration, char expectParameter);
int dcl(char *name, char *out, char expectParameter);
int dirdcl(char *name, char *out, char expectParameter);
int parameters(char *out);
int gettoken(void);
int getch(void);
void ungetch(int c);
int contains(char **strs, char *name, int strCount);
char *saferstrcat(char *dst, const char *str, size_t dstsize);
int error(char *msg);

int tokentype;
char token[MAXTOKEN];
int buf[BUFSIZE];
int bufp = 0;

static char *storageClasses[NUMOFSTORAGECLASSES] = { "_Thread_local", "auto", "extern", "register", "static" };
static char *typeQualifiers[NUMOFTYPEQUALIFIERS] = { "_Atomic", "const", "restrict", "volatile" };
static char *typeSpecifiers[NUMOFTYPESPECIFIERS] = { "_Bool", "_Complex", "char", "double", "float", "int", "long", "short", "signed", "unsigned", "void" };


int main(void)
{
    char out[MAXOUTPUT];
    while (gettoken() != EOF)
    {
        processDeclaration(out, FALSE);
        for (int c = tokentype; c != '\n' && c != EOF; ) // discard rest of line since last token could be ';' or an error occurred
            if ((c = getch()) == EOF)
                break;
    }
    return 0;
}

int processDeclaration(char *declaration, char expectParameter)
{
    char datatype[MAXTOKEN]; // stores type qualifier, specifier, and storage class info
    char name[MAXTOKEN]; // stores function/variable name
    char out[MAXOUTPUT]; // used to store information gathered by dcl/dirdcl to be used in the final output
    datatype[0] = '\0'; // ensure null terminated

    if (!(tokentype == STORAGECLASS || tokentype == TYPEQUALIFIER || tokentype == TYPESPECIFIER))
        return error("Error: expected a type");
    while (tokentype == STORAGECLASS || tokentype == TYPEQUALIFIER || tokentype == TYPESPECIFIER)
    {
        if (saferstrcat(datatype, " ", MAXTOKEN) == NULL)
            return error("Error: input too large to fit into buffer");
        if (saferstrcat(datatype, token, MAXTOKEN) == NULL)
            return error("Error: input too large to fit into buffer");
        gettoken(); // get tokens until no longer a token for datatype
    }
    for (int i = strlen(token) - 1; i >= 0; i--) // since the while loop gets an extra unneeded token, push it back in reverse order
        ungetch(token[i]);
    do
    {
        out[0] = '\0'; // ensure new out string each loop iteration
        if (dcl(name, out, expectParameter) == ERROR) // dcl updates out based on input
            return ERROR;
        else if (tokentype != ';' && tokentype != ',' && tokentype != ')' && tokentype != '\n') // if the returned output is not one of these chars, an error occurred
            return error("Syntax error");
        else
        {
            if (strcmp(datatype, " void") == 0 && strncmp(out + (strlen(out) - 10), " returning", 10) == 0)
                snprintf(datatype, MAXTOKEN, "%s", " nothing"); // if is function (has the word returning at the end) and it is returning only void, then improve readability by changing type to "nothing"
            if (strcmp(name, " unnamed") == 0) // if name starts with a space, then it is the special flag set by dirdcl for an unnamed parameter
                snprintf(name, MAXTOKEN, "%s", " unnamed parameter");
            if (expectParameter)
            {
                if (out[0] == ' ') // this improves the output formatting. It finds the first variable that starts with a space and replaces the space with a (
                    out[0] = '(';
                else if (datatype[0] == ' ')
                    datatype[0] = '(';
                snprintf(declaration, MAXOUTPUT, "%s %s%s)", name, out, datatype); // store data in declaration which is used by parameters function
            }
            else // if not expecting parameters, then this was called by main. print out English version of the declaration
                printf("%s:%s%s\n", name, out, datatype);
        }
    } while (!expectParameter && tokentype == ','); // loop is just in case received multiple comma separated declarations that aren't function parameters
    return OK;
}

int dcl(char *name, char *out, char expectParameter)
{
    int numPointers = 0;
    while (gettoken() == '*') // identify the number of back to back asterisks
        numPointers++;
    if (dirdcl(name, out, expectParameter) == ERROR)
        return ERROR;
    while (numPointers-- > 0)
        if (saferstrcat(out, " pointer to", MAXOUTPUT) == NULL)
            return error("Error: input too large to fit into buffer");
    return OK;
}

int dirdcl(char *name, char *out, char expectParameter)
{
    if (tokentype == '(') // ( dcl )
    {
        if (dcl(name, out, expectParameter) == ERROR)
            return ERROR;
        if (tokentype != ')')
            return error("Error: missing )");
    }
    else if (tokentype == VARIABLE)
        snprintf(name, MAXTOKEN, "%s", token);
    else if (expectParameter) // if tokentype is not VARIABLE and expecting a parameter, then it is an unnamed parameter
    {
        snprintf(name, MAXTOKEN, "%s", " unnamed"); // the space added is a flag indicates that this is an unnamed parameter instead of a named parameter called unnamed
        expectParameter = FALSE;
        for (int i = strlen(token) - 1; i >= 0; i--)
            ungetch(token[i]); // push unused token back to input in reverse order
    }
    else
        return error("Error: expected variable name or (dcl)");
    while (gettoken() == '(' || tokentype == BRACKETS)
    {
        if (tokentype == '(')
        {
            if (parameters(out) == ERROR) // found a function so parse its parameters
                return ERROR;
        }
        else
        {
            if (saferstrcat(out, " array", MAXOUTPUT) == NULL)
                return error("Error: input too large to fit into buffer");
            if (saferstrcat(out, token, MAXOUTPUT) == NULL)
                return error("Error: input too large to fit into buffer");
            if (saferstrcat(out, " of", MAXOUTPUT) == NULL)
                return error("Error: input too large to fit into buffer");
        }
    }
    return OK;
}

int parameters(char *out)
{
    char declaration[MAXOUTPUT], expectParameter = TRUE;
    int parameterCount = 0;

    if (gettoken() == ')') // previous token was '(' which means () was found, an old K&R style declaration
    {
        if (saferstrcat(out, " obsolescent non-prototype function declaration with unknown parameters returning", MAXOUTPUT) == NULL)
            return error("Error: input too large to fit into buffer");
        return OK;
    }
    else if (tokentype == TYPESPECIFIER && strcmp(token, "void") == 0)
    {
        if (gettoken() == ')') // this is true when the type is void and it is the only parameter
            expectParameter = FALSE;
        else if (tokentype == ',') // very basic check to see if void is used incorrectly. Too much work to do it properly
            return error("Syntax error: functions either can have void * parameters or only a single void parameter");
        else // the parameter is not (void), but rather pointer(s) to void (e.g. void *, void **, etc) or it is (int, void), etc.
        {
            for (int i = strlen(token) - 1; i >= 0; i--)
                ungetch(token[i]); // push unused token back to input in reverse order
            tokentype = TYPESPECIFIER; // reset tokentype since not (void)
            snprintf(token, MAXTOKEN, "%s", "void"); // reset token since not (void)
        }
    }
    // the ##### is used for padding and will be changed later. 5 #'s are to prevent buffer overflows caused by an insanely large input that fits in an oversized buffer
    if (saferstrcat(out, " function expecting ##### parameters:", MAXOUTPUT) == NULL)
        return error("Error: input too large to fit into buffer");
    if (expectParameter)
        do
        {
            if (parameterCount++ > 0) // don't call gettoken the first time, but call it each time thereafter
                gettoken();
            if (processDeclaration(declaration, expectParameter) == ERROR)
                return ERROR;
            if (strncmp(declaration, " unnamed parameter ", 19) != 0) // check if declaration starts with string
                if (saferstrcat(out, " parameter ", MAXOUTPUT) == NULL) // if parameter has a name, prefix out first before adding the declaration part
                    return error("Error: input too large to fit into buffer");
            if (saferstrcat(out, declaration, MAXOUTPUT) == NULL)
                return error("Error: input too large to fit into buffer");
        } while (tokentype == ','); // get all comma separated parameters
    if (tokentype == ')') // after getting parameters, next token should be )
    {
        // this complicated mess is so I can replace the "##### parameters:" string with the parameterMessage in the final output
        char parameterMessage[MAXTOKEN], *p1 = out, *p2 = parameterMessage;
        while (*p1 != '#') // move to first #. this will run before another "##### parameters" is added for the same declaration
            p1++;
        if (parameterCount == 0)
            snprintf(parameterMessage, MAXTOKEN, "no parameters");
        else if (parameterCount == 1)
            snprintf(parameterMessage, MAXTOKEN, "1 parameter:");
        else
            snprintf(parameterMessage, MAXTOKEN, "%d parameters:", parameterCount);
        while (*p2 != '\0') // copy parameterMessage to out until '\0' is reached. Don't copy '\0'
            *p1++ = *p2++;
        for (p2 = p1; *p2++ != ':'; ) // point p2 to p1 and then move p2 to after "##### parameters:"
            ;
        while ((*p1++ = *p2++)) // copy after the : to the end of out to where p1 is pointing (the end of the parameterMessage in out)
            ;
        if (saferstrcat(out, " returning", MAXOUTPUT) == NULL)
            return error("Error: input too large to fit into buffer");
    }
    else
        return error("Error: expected closing parentheses after parameters");
    return OK;
}

int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t') // skip spaces and tabs
        ;
    if (c == '(')
    {
        *(p + 1) = '\0'; // terminate token string
        return *p = tokentype = '(';;
    }
    else if (c == '[') // get [#####] and store in token
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c) || c == '_') // get name
    {
        for (*p++ = c; isalnum(c = getch()) || c == '_'; )
            *p++ = c;
        *p = '\0';
        ungetch(c); // push back the unneeded extra char
        if (contains(typeSpecifiers, token, NUMOFTYPESPECIFIERS))
            return tokentype = TYPESPECIFIER;
        else if (contains(storageClasses, token, NUMOFSTORAGECLASSES))
            return tokentype = STORAGECLASS;
        else if (contains(typeQualifiers, token, NUMOFTYPEQUALIFIERS))
            return tokentype = TYPEQUALIFIER;
        return tokentype = VARIABLE;
    }

    *(p + 1) = '\0'; // terminate token string
    return *p = tokentype = c; // since not one of the types above, return char as the type and store it's value in the token
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        fprintf(stderr, "ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int contains(char **strs, char *name, int strCount)
{
    for (int i = 0; i < strCount; i++)
        if (strcmp(strs[i], name) == 0)
            return TRUE;
    return FALSE;
}

// concatenates str to end of dst; requires null terminated strings and dst buffer size. Returns null if provided bad pointers or buffer is too small, otherwise returns pointer to dst
char *saferstrcat(char *dst, const char *str, size_t dstsize)
{
    if (dst == NULL || str == NULL) // if either pointer is NULL, return NULL
        return NULL;
    char *dstStart = dst; // keep track of the base of the string
    size_t dstLen = strlen(dst), strLen = strlen(str); // calcuate the length of both strings once. Prevents the need to do constant checks in the loop
    if (dstLen + strLen >= dstsize) // strlen doesn't count '\0', so if size == dstsize, then not enough space for the '\0' at the end
        return NULL; // concatenating the strings would result in a buffer overflow. So return NULL instead
    dst += dstLen; // move pointer to '\0' at end of string
    while ((*dst++ = *str++)) // copy str to end of dst until str == '\0'. If str == "", the loop copies '\0' and terminates
        ;
    return dstStart;
}

int error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    return ERROR;
}




