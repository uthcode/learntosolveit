" Vim syntax file
" Language: reStructuredText Documentation Format
" Maintainer: Estienne Swart 
" URL: http://www.sanbi.ac.za/~estienne/vim/syntax/rest.vim
" Latest Revision: 2004-04-26
"
" A reStructuredText syntax highlighting mode for vim.
" (derived somewhat from Nikolai Weibull's <source@p...>
" source)

"TODO:
" 0. Make sure that no syntax highlighting bleeding occurs!
" 1. Need to fix up clusters and contains.
" 2. Need to validate against restructured.txt.gz and tools/test.txt.
" 3. Fixup superfluous matching.
" 4. I need to figure out how to keep a running tally of the indentation in order
" to enable block definitions, i.e. a block ends when its indentation drops
" below that of the existing one.
" 5. Define folding patterns for sections, etc.
" 6. Setup a completion mode for target references to hyperlinks

" Remove any old syntax stuff that was loaded (5.x) or quit when a syntax file
" was already loaded (6.x).
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

"syn match rstJunk "\\_"

"ReStructuredText Text Inline Markup:
syn region rstEmphasis start=+\*[^*]+ end=+\*+ 
syn region rstStrongEmphasis start=+\*\*[^*]+ end=+\*\*+ 
syn region rstInterpretedText start=+`[^`]+ end=+`+ contains=rstURL
syn region rstInlineLiteral start="``" end="``" contains=rstURL
"Using a syn region here causes too much to be highlighted.

syn region rstSubstitutionReference start=+|\w+ end=+\w|+ skip=+\\|+
"I'm forcing matching of word characters before and after '|' in order to
"prevent table matching (this causes messy highlighting)

syn region rstGridTable start=/\n\n\s*+\([-=]\|+\)\+/ms=s+2 end=/+\([-=]\|+\)\+\n\s*\n/me=e-2

syn match rstRuler "\(=\|-\|+\)\{3,120}"

" syn match rstInlineInternalTarget "_`\_.\{-}`"
syn region rstInlineInternalHyperlink start=+_`+ end=+`+ contains=rsturl
" this messes up with InterpretedText

syn match rstFootnoteReference "\[\%([#*]\|[0-9]\+\|#[a-zA-Z0-9_.-]\+\)\]_"
"syn region rstCitationReference start=+\[+ end=+\]_+
"syn match rstCitationReferenceNothing +\[.*\]+
"TODO: fix Citation reference - patterns defined still cause "bleeding"
"if end doesn't get matched, catch it first with another pattern - this is ugly???
syn match rstURL "\(acap\|cid\|data\|dav\|fax\|file\|ftp\|gopher\|http\|https\|imap\|ldap\|mailto\|mid\|modem\|news\|nfs\|nntp\|pop\|prospero\|rtsp\|service\|sip\|tel\|telnet\|tip\|urn\|vemmi\|wais\):[-./[:alnum:]_~@]\+"
"I need a better regexp for URLs here. This doesn't cater for URLs that are
"broken across lines

" hyperlinks
syn match rstHyperlinks /`[^`]\+`_/
"syn region rstHyperlinks start="`\w" end="`_"
syn match rstExternalHyperlinks "\w\+_\w\@!"
"This seems to overlap with the ReStructuredText comment?!?

"ReStructuredText Sections:
syn match rstTitle ".\{2,120}\n\(\.\|=\|-\|=\|`\|:\|'\|\"\|\~\|\^\|_\|\*\|+\|#\|<\|>\)\{3,120}"
" [-=`:'"~^_*+#<>]
"for some strange reason this only gets highlighted upon refresh

"syn match rstTitle "\w.*\n\(=\|-\|+\)\{2,120}"

"ReStructuredText Lists:
syn match rstEnumeratedList "^\s*\d\{1,3}\.\s"

syn match rstBulletedList "^\s*\([+-]\|\*\)\s"
" syn match rstBulletedList "^\s*[+-]\|\*\s"
"I'm not sure how to include "*" within a range []?!?
" this seems to match more than it should :-(


syn match rstFieldList ":[^:]\+:\s"me=e-1 contains=rstBibliographicField
"still need to add rstDefinitionList  rstOptionList

"ReStructuredText Preformatting:
syn match rstLiteralBlock "::\s*\n" contains=rstGridTable
"syn region rstLiteralBlock start=+\(contents\)\@<!::\n+ end=+[^:]\{2}\s*\n\s*\n\s*+me=e-1 contains=rstEmphasis,rstStrongEmphasis,rstInlineLiteral,rstRuler,rstFieldList,rstInlineInternalTargets,rstGridTable transparent
"Add more to allbut?
"This command currently ignores the 'contents::' line that is found in some
"restructured documents.
"syn region rstBlockQuote start=+\s\n+ end=+[^:]\{2}\s*\n\s*\n\s*+me=e-1 contains=ALLBUT,rstEmphasis,rstStrongEmphasis,rstInlineLiteral,rstRuler
"FIX rstBlockQuote

"syn match rstDocTestBlock
"
"
"RestructureText Targets:
syn match rstFootnoteTarget "\[\%([#*]\|[0-9]\+\|#[a-zA-Z0-9_.-]\+\)\]" contained
syn region rstCitationTarget start=+\[+ end=+\]+ contained
"syn region rstInlineInternalTarget start=+_\_s\@!+ end=+\:+ contained
"seems to match things in reagions it should not
syn match rstDirective +\.\.\s\{-}[^_]\{-}\:\:+ms=s+3 contained

"ReStructuredText Comments:
syn region rstComment matchgroup=rstComment start="\.\{2} " end="^\s\@!" contains=rstFootnoteTarget,rstCitationTarget,rstInlineInternalTarget,rstDirective,rstURL
"THIS NEEDS TO BE FIXED TO HANDLE COMMENTS WITH PARAGRAPHS
"It can be modelled on rstBlock (which also needs to be worked)
"It also matches too much :-( e.g. normal ellipsis
"Define fold group for comments?

"ReStructuredText Miscellaneous:

syn keyword rstBibliographicField contained Author Organization Contact Address Version Status Date Copyright Dedication Abstract Authors
"keyword revison too??? Lower case variants too?

" todo
syn keyword rstTodo contained FIXME TODO XXX

syn region rstQuotes start=+\"+ end=+\"+ skip=+\\"+ contains=ALLBUT,rstEmphasis,rstStrongEmphasis,rstBibliographicField

" footnotes
"syn region rstFootnote matchgroup=rstDirective start="^\.\.\[\%([#*]\|[0-9]\+\|#[a-z0-9_.-]\+\)\]\s" end="^\s\@!" contains=@rstCruft

" citations
"syn region rstCitation matchgroup=rstDirective start="^\.\.\[[a-z0-9_.-]\+\]\s" end="^\s\@!" contains=@rstCruft

syn region rstBlock start="::\(\n\s*\)\{-}\z(\s\+\)" skip="^$" end="^\z1\@!" fold contains=ALLBUT,rstInterpretedText,rstFootnoteTarget,rstCitationTarget,rstInlineInternalTarget
"almost perfect
"Still need to get stop on unident correct. Also need to work on recursive
"blocking for proper folding.
"TODO: Define syntax regions for Sections (defined by titles)

syn sync minlines=50

if !exists("did_rst_syn_inits")
    let did_rst_syn_inits = 1
   
    hi link rstBibliographicField Operator
    hi link rstBlock Type
    hi link rstExternalHyperlinks Underlined 
    hi link rstHyperlinks Underlined
    hi link rstTitle Constant
    hi link rstRuler Special
    hi link rstURL Underlined
    hi link rstSubstitutionReference Macro
    hi link rstEmphasis Exception
    hi link rstStrongEmphasis Exception
    hi link rstLiteralBlock Type
    hi link rstBlockQuote Type
    hi link rstEnumeratedList Operator
    hi link rstBulletedList Operator
    hi link rstFieldList Label
    hi link rstTodo Todo
    hi link rstComment Comment
    hi link rstGridTable Delimiter
    hi link rstInlineLiteral Function
    hi link rstInterpretedText Keyword
    hi link rstInlineInternalHyperlink Identifier
    hi link rstInlineInternalTarget Identifier
    hi link rstFootnoteReference Identifier
    hi link rstCitationReference Identifier
    hi link rstFootnoteTarget Identifier
    hi link rstCitationTarget Identifier
    hi link rstDirective Underlined
endif

let b:current_syntax = "rst"

" vim: set sts=4 sw=4:
