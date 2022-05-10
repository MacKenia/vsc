package xyz.mac.model;

import com.baomidou.mybatisplus.annotation.TableName;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
@TableName("ping")
public class Message {
    String content;
    int read_flag;
}
