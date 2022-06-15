let mapleader=" "

syntax on

set mouse=a
set clipboard=unnamed
set expandtab
set number
set cursorline
set wrap
set wildmenu
set showcmd
set sw=4

set hlsearch
exec "nohlsearch"
set incsearch
set ignorecase
set smartcase

filetype on
filetype indent on
filetype plugin on
filetype plugin indent on

map ee :e .<CR>
map Q :q!<CR>
map S :w<CR>
map R :source $MYVIMRC<CR>

noremap <LEADER><CR> :nohlsearch<CR>

map sk :set nosplitbelow<CR>:split<CR>
map sj :set splitbelow<CR>:split<CR>
map sl :set splitright<CR>:vsplit<CR>
map sh :set nosplitright<CR>:vsplit<CR>

map fk <C-w>k
map fj <C-w>j
map fh <C-w>h
map fl <C-w>l

map tt :tabe<CR>
map tn :tabn<CR>
map tp :tabp<CR>

map <C-c> y

call plug#begin('~/.config/nvim/plugged')

Plug 'vim-airline/vim-airline'
Plug 'connorholyday/vim-snazzy'
Plug 'neoclide/coc.nvim',{'branch':'release'}
Plug 'eluum/vim-autopair'
Plug '907th/vim-auto-save'
Plug 'cdelledonne/vim-cmake'

call plug#end()

" make background transparent
let g:SnazzyTransparent = 1

color snazzy

let g:auto_save = 1 " enble Autosave on vim startup

let g:coc_global_extensions = [
	\ 'coc-json',
	\ 'coc-vimlsp',
	\ 'coc-clangd']

" use <TAB> to complete code
inoremap <silent><expr> <TAB>
      \ pumvisible() ? "\<C-n>" :
      \ <SID>check_back_space() ? "\<TAB>" :
      \ coc#refresh()
inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<C-h>"

function! s:check_back_space() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" Use K t show documentation in preview window.
nnoremap <silent> <C-h> :call <SID>show_documentation()<CR>

function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  elseif (coc#rpc#ready())
    call CocActionAsync('doHover')
  else
    execute '!' . &keywordprg . " " . expand('<cword>')
  endif
endfunction


