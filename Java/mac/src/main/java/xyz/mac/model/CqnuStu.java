package xyz.mac.model;

import com.baomidou.mybatisplus.annotation.TableName;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("cqnu_students_info")
public class CqnuStu {
    private long id;
    private String name;
    private String grade;
    private String _class;
    private String academy;
    private String major;
    private String phone;
    private String qq;
}
