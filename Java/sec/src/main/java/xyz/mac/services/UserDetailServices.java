package xyz.mac.services;

import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

import xyz.mac.mapper.AuthorityMapper;
import xyz.mac.mapper.UserInfoMapper;
import xyz.mac.model.Authority;
import xyz.mac.model.UserInfos;

@Service
public class UserDetailServices implements UserDetailsService{

    @Autowired
    private UserInfoMapper userInfo;

    @Autowired
    private AuthorityMapper authorityMapper;

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        UserInfos user = userInfo.selectByName(username);
        List<Authority> auth = authorityMapper.findAuthoritiesByUsername(username);
        List<SimpleGrantedAuthority> list = auth.stream().map(a -> new SimpleGrantedAuthority(a.getAuthority())).collect(Collectors.toList());
        if (user != null) {
            UserDetails userDetails = new User(user.getUser(), user.getPasswd(), list);
            return userDetails;
        } else {
            throw new UsernameNotFoundException("用户名不存在");
        }
    }
    
}
