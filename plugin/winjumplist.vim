" File:         winjumplist.vim
" Description:  Vim plugin that provides Jump List support on Windows
" Maintainer:   Eli Young <elyscape at gmail dot com>
" Version:      1.0.0

if exists('g:loaded_winjumplist') || !has('gui_win32') || !has('libcall')
  finish
endif
let g:loaded_winjumplist = 1

if !exists('g:winjumplist_excludes')
  let g:winjumplist_excludes = ['\v\\doc\\[^\\]+\.txt$']
endif

let s:librarypath = expand('<sfile>:p:h') . '\vim-winjumplist-' . (has('win64') ? '64' : '32')

function! s:add_to_jump_list(path)
  for exclude in g:winjumplist_excludes
    if a:path =~ exclude
      return
    endif
  endfor
  call libcall(s:librarypath, 'addToJumpList', a:path)
endfunction

au BufReadPost * call s:add_to_jump_list(expand('<afile>:p'))
