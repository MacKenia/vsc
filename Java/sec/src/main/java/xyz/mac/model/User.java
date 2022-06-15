package xyz.mac.model;

import java.io.Serializable;

import com.fasterxml.jackson.databind.ser.std.SerializableSerializer;

import lombok.Data;

@Data
public class User implements Serializable{
    private Integer id;
    private String username;
}
