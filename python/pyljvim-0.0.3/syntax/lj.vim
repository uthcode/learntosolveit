" Vim syntax file
" Language:	LiveJournal Post file.	
" Maintainer:	Wartan Hachaturow <wart@tepkom.ru>
" Last Change:	2002 Nov 04

" Initial revision, based on mail.vim.

if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

" The LJ header is recognized starting with a "Subject:" line and ending
" with an empty line or other line that can't be in the header.
" All lines of the header are highlighted
" For "Subject " matching case is required, not for the rest.
syn region	ljHeader	start="^Subject " skip="^[ \t]" end="^[-A-Za-z0-9/]*[^-A-Za-z0-9/:]"me=s-1 end="^[^:]*$"me=s-1 end="^---*" contains=ljHeaderKey,ljSubject

syn case ignore

syn region	ljHeader	start="^\(Subject:\|Mood:\|Security:\|Music:\|Journal:\)" skip="^[ \t]" end="^[-a-z0-9/]*[^-a-z0-9/:]"me=s-1 end="^[^:]*$"me=s-1 end="^---*" contains=ljHeaderKey,ljSubject,ljSecurity

syn region	ljHeaderKey	contained start="^\(Subject\|Journal\).*" skip=",$" end="$" 

syn match	ljSubject	contained "^Subject.*"

syn region	ljSecurity	start="^Security:.*" end="$" contains=ljSecurityTypes
syn match	ljSecurityTypes	contained "\(public\|private\|friends\)"

syn match	ljString	contained ".*"

syn region	ljSignature	start="^-- *$" end="^$"

" even and odd quoted lines
" removed ':', it caused too many bogus highlighting
" order is imporant here!
syn match	ljQuoted1	"^\([A-Za-z]\+>\|[]|}>]\).*$"
syn match	ljQuoted2	"^\(\([A-Za-z]\+>\|[]|}>]\)[ \t]*\)\{2}.*$"
syn match	ljQuoted3	"^\(\([A-Za-z]\+>\|[]|}>]\)[ \t]*\)\{3}.*$"
syn match	ljQuoted4	"^\(\([A-Za-z]\+>\|[]|}>]\)[ \t]*\)\{4}.*$"
syn match	ljQuoted5	"^\(\([A-Za-z]\+>\|[]|}>]\)[ \t]*\)\{5}.*$"
syn match	ljQuoted6	"^\(\([A-Za-z]\+>\|[]|}>]\)[ \t]*\)\{6}.*$"

" Need to sync on the header.  Assume we can do that within a hundred lines
syn sync lines=100

" Define the default highlighting.
" For version 5.7 and earlier: only when not done already
" For version 5.8 and later: only when an item doesn't have highlighting yet
if version >= 508 || !exists("did_ahdl_syn_inits")
  if version < 508
    let did_ahdl_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  HiLink ljHeaderKey		Type
  HiLink ljHeader		Statement
  HiLink ljQuoted1		Comment
  HiLink ljQuoted3		Comment
  HiLink ljQuoted5		Comment
  HiLink ljQuoted2		Identifier
  HiLink ljQuoted4		Identifier
  HiLink ljQuoted6		Identifier
  HiLink ljSignature		PreProc
  HiLink ljSubject		String
  HiLink ljSecurity		Type
  HiLink ljSecurityTypes	Special

  delcommand HiLink
endif

let b:current_syntax = "lj"

" vim: ts=8
