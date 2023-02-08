require("auto-save").setup{{
        trigger_event = {"InsertLeave", "TextChanged","BufLeave"},
        write_all_buffers = true
    }
}
