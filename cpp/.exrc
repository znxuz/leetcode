let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <S-Tab> <Cmd>call v:lua.cmp.utils.keymap.set_map(17)
cnoremap <silent> <Up> <Cmd>call v:lua.cmp.utils.keymap.set_map(9)
inoremap <silent> <Up> <Cmd>call v:lua.cmp.utils.keymap.set_map(8)
cnoremap <silent> <Down> <Cmd>call v:lua.cmp.utils.keymap.set_map(5)
inoremap <silent> <Down> <Cmd>call v:lua.cmp.utils.keymap.set_map(4)
noremap! <silent> <Plug>luasnip-expand-repeat <Cmd>lua require'luasnip'.expand_repeat()
noremap! <silent> <Plug>luasnip-delete-check <Cmd>lua require'luasnip'.unlink_current_if_deleted()
inoremap <silent> <Plug>luasnip-jump-prev <Cmd>lua require'luasnip'.jump(-1)
inoremap <silent> <Plug>luasnip-jump-next <Cmd>lua require'luasnip'.jump(1)
inoremap <silent> <Plug>luasnip-prev-choice <Cmd>lua require'luasnip'.change_choice(-1)
inoremap <silent> <Plug>luasnip-next-choice <Cmd>lua require'luasnip'.change_choice(1)
inoremap <silent> <Plug>luasnip-expand-snippet <Cmd>lua require'luasnip'.expand()
inoremap <silent> <Plug>luasnip-expand-or-jump <Cmd>lua require'luasnip'.expand_or_jump()
nnoremap  <Cmd>nohlsearch|diffupdate|normal! 
nnoremap  <Cmd>VimwikiNextLink
nnoremap  <Cmd>VimwikiPrevLink
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
noremap <silent> ,di <Cmd>lua require("packer.load")({'nvim-dap-ui'}, { keys = "<leader>di", prefix = "" }, _G.packer_plugins)
nnoremap ,u <Cmd>UndotreeToggle
nnoremap , <Cmd>ClangdSwitchSourceHeader
nnoremap ,es <Cmd>lua vim.diagnostic.open_float()
nnoremap ,en <Cmd>lua vim.diagnostic.goto_next()
nnoremap ,ep <Cmd>lua vim.diagnostic.goto_prev()
nnoremap ,ec <Cmd>FzfLua lsp_document_diagnostics
nnoremap ,ee <Cmd>FzfLua lsp_workspace_diagnostics
nnoremap ,sc <Cmd>FzfLua lsp_document_symbols
nnoremap ,ss <Cmd>FzfLua lsp_live_workspace_symbols
nnoremap ,ca <Cmd>FzfLua lsp_code_actions
nnoremap ,re <Cmd>lua vim.lsp.buf.rename()
nnoremap ,fm <Cmd>FzfLua man_pages
nnoremap ,ft <Cmd>FzfLua help_tags
nnoremap ,fo <Cmd>FzfLua oldfiles
nnoremap ,fj <Cmd>FzfLua jumps
nnoremap ,fq <Cmd>FzfLua quickfix
nnoremap ,fr <Cmd>FzfLua resume
nnoremap ,fa <Cmd>FzfLua builtin
nnoremap ,gi <Cmd>lua require("config.fzflua").grep_in()
nnoremap ,gc <Cmd>FzfLua live_grep cwd=%:p:h
nnoremap ,gg <Cmd>FzfLua live_grep
nnoremap ,fb <Cmd>FzfLua buffers
nnoremap ,fi <Cmd>lua require("config.fzflua").find_files_in()
nnoremap ,fh <Cmd>FzfLua files cwd=~
nnoremap ,fc <Cmd>FzfLua files cwd=%:p:h
nnoremap ,ff <Cmd>FzfLua files
nnoremap ,ws <Cmd>VimwikiUISelect
nnoremap ,nc <Cmd>NnnPicker %:p:h
nnoremap ,nn <Cmd>NnnPicker
nnoremap , <Cmd>lua require("config.general").search_cppman_cursor()
nnoremap Y y$
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
xmap a% <Plug>(MatchitVisualTextObject)
nnoremap gr <Cmd>FzfLua lsp_references
nnoremap gp <Cmd>FzfLua lsp_implementations
nnoremap gd <Cmd>FzfLua lsp_definitions
nnoremap gh <Cmd>lua vim.lsp.buf.hover()
nnoremap gD <Cmd>FzfLua lsp_typedefs
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
snoremap <silent> <Plug>luasnip-jump-prev <Cmd>lua require'luasnip'.jump(-1)
snoremap <silent> <Plug>luasnip-jump-next <Cmd>lua require'luasnip'.jump(1)
snoremap <silent> <Plug>luasnip-prev-choice <Cmd>lua require'luasnip'.change_choice(-1)
snoremap <silent> <Plug>luasnip-next-choice <Cmd>lua require'luasnip'.change_choice(1)
snoremap <silent> <Plug>luasnip-expand-snippet <Cmd>lua require'luasnip'.expand()
snoremap <silent> <Plug>luasnip-expand-or-jump <Cmd>lua require'luasnip'.expand_or_jump()
noremap <silent> <Plug>luasnip-expand-repeat <Cmd>lua require'luasnip'.expand_repeat()
noremap <silent> <Plug>luasnip-delete-check <Cmd>lua require'luasnip'.unlink_current_if_deleted()
tmap <Plug>(cmp.utils.keymap.normalize) 
tnoremap <silent> <Plug>(fzf-normal) 
tnoremap <silent> <Plug>(fzf-insert) i
nnoremap <silent> <Plug>(fzf-normal) <Nop>
nnoremap <silent> <Plug>(fzf-insert) i
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v'):if col("''") != col("$") | exe ":normal! m'" | endifgv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
nnoremap <M-k> <Cmd>lua require("config.general").search_cppman_prompt()
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(7)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(6)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(12)
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(3)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(2)
cnoremap <silent> 	 <Cmd>call v:lua.cmp.utils.keymap.set_map(13)
inoremap  <Cmd>lua vim.lsp.buf.signature_help()
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(1)
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(16)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(15)
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(11)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(10)
inoremap  u
inoremap  u
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(14)
cnoremap ,cd =substitute(expand("%:p:h"), getcwd(), '.', '').'/'
let &cpo=s:cpo_save
unlet s:cpo_save
set autowrite
set cinoptions=g0
set clipboard=unnamedplus
set completeopt=menuone,noinsert
set exrc
set guicursor=a:block
set helplang=en
set nohlsearch
set ignorecase
set laststatus=3
set pumheight=20
set runtimepath=~/.config/nvim,/etc/xdg/nvim,~/.local/share/nvim/site,~/.local/share/nvim/site/pack/packer/start/packer.nvim,~/.local/share/nvim/site/pack/*/start/*,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/site/pack/packer/start/packer.nvim,/usr/share/nvim/site/pack/*/start/*,/usr/share/nvim/runtime,/usr/share/nvim/runtime/pack/dist/opt/matchit,/lib/nvim,~/.local/share/nvim/site/pack/*/start/*/after,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,~/.local/share/nvim/site/after,/etc/xdg/nvim/after,~/.config/nvim/after,/usr/share/vim/vimfiles
set secure
set shiftwidth=4
set shortmess=filnxtToOFc
set noshowcmd
set smartcase
set statusline=%#STLMode#%{'\ \ '.toupper(mode()).'\ '}%#STL#%#STLMode#%{&readonly?'\ |\ '.'RO\ ':''}%#STL#%#STLMode#%{&paste?'\ |\ '.'P\ ':''}%#STL#%<%{'\ \ '.fnamemodify(getcwd(),':~')}%{expand('%')==''?'':'\ \ |\ '.fnamemodify(expand('%:p'),\ ':~:.')}%{&modified?'\ \ '.'[+]':''}%=%{'\ \ \ \ '.&fileformat}%{'\ \ |\ '}%{&fileencoding?&fileencoding:&encoding}%{'\ '.'\ |\ '}%l:%c%{'\ |\ '}%p%%%{&filetype==''?'\ ':'\ |\ '.toupper(&filetype).'\ '}
set noswapfile
set tabstop=4
set termguicolors
set ttimeoutlen=0
set undodir=~/.local/share/nvim/undodir
set undofile
set wildignorecase
set wildmode=longest:list:lastused,full
set window=48
" vim: set ft=vim :
