package xyz.mac.model;

import java.io.Serializable;

import lombok.Data;

@Data
public class User implements Serializable{
    private Integer id;
    private String username;
}
