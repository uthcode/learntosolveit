===============
C++ Programming
===============


Questions
=========

#) What are Virtual Tables?

#) What is const-correctness?

Snippet 1
---------
::

    #include<iostream>
    #include<string>
    #include<vector>
    #include<set>
    #include<map>
    #include<algorithm>

    using namespace std;

    class CLASSNAME {
        public:
            // method name
            int foo()
            {
                return 0;
            }
    };

    int main(int argc, char *argv[])
    {
        CLASSNAME obj;
    }

Snippet 2
---------
::

    #include <iostream>
    #include <ostream>
    #include <limits>

    using namespace std;

    int main()
    {

        typedef std::numeric_limits< double > dl;
        typedef std::numeric_limits< float > fl;

        cout << "double:\n";
        cout << "\tdigits (bits):\t\t" << dl::digits << endl;
        cout << "\tdigits (decimal):\t" << dl::digits10 << endl;

        cout << endl;

        cout << "float:\n";
        cout << "\tdigits (bits):\t\t" << fl::digits << endl;
        cout << "\tdigits (decimal):\t" << fl::digits10 << endl;

    }



Snippet 3
---------
::

    typedef vector<int> vi; 
    typedef vector<vi> vvi; 
    typedef pair<int,int> ii; 

    #define sz(a) int((a).size()) 
    #define pb push_back 
    #define all(c) (c).begin(),(c).end() 
    #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
    #define present(c,x) ((c).find(x) != (c).end()) 
    #define cpresent(c,x) (find(all(c),x) != (c).end()) 
    #define all(c) c.begin(), c.end()
    #define tr(container, it) \
        for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

    #include<map>
    #include<iostream>

    #define tr(container, it) \
        for(typeof(container.begin()) it = container.begin(); it !=container.end(); it++)

    using namespace std;

    int main(int argc, char *argv[])
    {
        map<int, int> m1;
        m1[1] = 100;
        m1[2] = 200;
        m1[3] = 300;
        tr(m1,it)
            cout<<it->first<<" "<<it->second<<endl;
    }

Snippet 4
---------
::


    #include<map>
    #include<iostream>

    #define tr(container, it) \
        for(typeof(container.begin()) it = container.begin(); it !=container.end(); it++)
    using namespace std;

    int main(int argc, char *argv[])
    {
        map<int, int> m1;
        m1[1] = 100;
        m1[2] = 200;
        m1[3] = 300;
        tr(m1,it)
            cout<<it->first<<" "<<it->second<<endl;
    }


Snippet 5
---------

::

    #include<iostream>
    #include<map>
    #include<string>

    using namespace std;

    int main(int argc, char *argv[])
    {
        map<int,int> mymap;
        map<string,string> mystrmap;
        mymap[10] = 100;
        mystrmap["senthil"] = "kumaran";
        cout<<mymap[10]<<endl;
        cout<<mystrmap["senthil"]<<endl;
    }


Snippet 6
---------

::

    #include <vector>
    #include <string>
    #include <iostream>

    using namespace std;

    class StringBuilder {
        public: 
            string buildString(vector<char> array)
            {
                // create a string for vector
                string s;
                
                // loop over every element in the array.

                for (int i = 0; i < array.size(); i++)
                {
                    s = s + array[i];
                }

                return s;
            }
    };

    int main() {
        StringBuilder myStr;
        vector<char> myvect(10);
        for (int i=0; i < myvect.size(); i++) {
            myvect[i] = i;
        }
        cout << myStr.buildString(myvect);
        return 0;
    }


Snippet 7
---------
::

    #include<vector>
    #include<iostream>

    using namespace std;

    class Something
    {
        public:
            int foo()
            {
                return 10;
            }
            int bar()
            {
                return foo();
            }
    };

    int main(int argc, char *argv[])
    {
        vector <pair <int, int> > cords;
        cords.push_back(make_pair(1,-1));
        cords.push_back(make_pair(0,-1));
        int i;
        for (i =0; i < cords.size(); i++)
            cout<<cords[i].first<<" "<<cords[i].second<<endl;
        Something obj;
        cout<<obj.bar();
    }
