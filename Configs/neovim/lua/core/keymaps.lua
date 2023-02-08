vim.g.mapleader = " "

local keymap = vim.keymap

-- keymap.set('i','jk','<ESC>')

keymap.set('v','J',":m '>+1<CR>gv=gv")
keymap.set('v','K',":m '<-2<CR>gv=gv")

keymap.set('n', '<leader>sv', '<C-w>v') -- 水平新增窗口 
keymap.set('n', '<leader>sh', '<C-w>s') -- 垂直新增窗口
keymap.set('n','Q',':q!<CR>')
keymap.set('n','S',':w<CR>')

keymap.set('n','<leader><CR>',':nohl<CR>')

keymap.set('n', 'L', ':bnext<CR>')
keymap.set('n', 'H', ':bprevious<CR>')

keymap.set('n','<leader>e',':NvimTreeToggle<CR>')
