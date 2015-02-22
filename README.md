# winjumplist.vim

Windows 7 introduced a feature called [Jump Lists][jump-lists], which offer easy
access to recently-used files. Unfortunately, Vim doesn't populate support it.
Well, winjumplist.vim is here to save the day.

## How it works

Windows populates the recent items in an application's Jump List from the
entries it has added to the Recent Documents list in the Start menu. Files are
added to the Recent Documents list when either of two things happen:

1. The user double-clicks on a file in Explorer.
2. The application calls [`SHAddToRecentDocs()`][shaddtorecentdocs].

While Vim doesn't call `SHAddToRecentDocs()`, if you've associated any
extensions with Vim, you may notice that files you've opened from Explorer have
been added to Vim's Jump List. winjumplist.vim calls `SHAddToRecentDocs()` when
Vim opens files so that you can get the full benefit of having Jump Lists.

## Installation

If you don't have a plugin manager, I highly recommend getting one.

* [Pathogen][pathogen]
  * `git clone https://github.com/elyscape/vim-winjumplist.git
    ~/vimfiles/bundle/vim-winjumplist`
* [NeoBundle][neobundle]
  * `NeoBundle 'elyscape/vim-winjumplist'`
* [Vundle][vundle]
  * `Plugin 'elyscape/vim-winjumplist'`
* Manual install
  * copy the files into your `~/vimfiles` directory

## Customization

You can tell winjumplist.vim to ignore certain files by setting
`g:winjumplist_excludes` to be an array of regular expressions that match file
paths you don't want added to Vim's Jump List. It defaults to
`['\v\\doc\\[^\\]+\.txt$']`, which should match any Vim help files.

## Requirements and caveats

* Obviously, this only does anything on Windows.
* Your copy of Vim must have been compiled with the libcall feature for
  winjumplist.vim to do anything. Most standard Windows distributions of Vim,
  including the official binary, include libcall.
* Files without extensions are not added to the Recent Documents list. This is a
  limitation of Windows itself and therefore not something I can fix.
* winjumplist.vim does not work with the console version of Vim and will
  silently refuse to load.

## Things to be aware of

Since `SHAddToRecentDocs()` is a Windows API function, calling it requires the
use of a compiled DLL. For your convenience, I have provided precompiled DLLs
for both 32-bit and 64-bit versions of Vim. If you don't trust me and want to
build it yourself, I've included everything you need to do so. Just fire up
Visual Studio and do a release build on the included solution. If you don't have
a copy of Visual Studio, [Visual Studio Community][visual-studio] is available
for free.

[jump-lists]: http://windows.microsoft.com/en-us/windows7/products/features/jump-lists
[shaddtorecentdocs]: https://msdn.microsoft.com/en-us/library/windows/desktop/bb762105(v=vs.85).aspx
[pathogen]: https://github.com/tpope/vim-pathogen
[neobundle]: https://github.com/Shougo/neobundle.vim
[vundle]: https://github.com/gmarik/vundle
[visual-studio]: http://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx
