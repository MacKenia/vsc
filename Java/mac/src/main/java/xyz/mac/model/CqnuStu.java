package xyz.mac.model;

import java.io.Serializable;

import com.baomidou.mybatisplus.annotation.TableName;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@TableName("cqnu_students_info")
public class CqnuStu implements Serializable{
    private static final long serialVersionUID=1L;
    private long id;
    private String name;
    private String grade;
    private String _class;
    private String academy;
    private String major;
    private String phone;
    private String qq;
}
