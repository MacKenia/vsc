package xyz.mac.configs;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

import xyz.mac.mapping.SecurityMapper;
import xyz.mac.model.Security;

@EnableWebSecurity
public class SecurityConf extends WebSecurityConfigurerAdapter{
    @Autowired
    private SecurityMapper securityMapper;

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception{
        BCryptPasswordEncoder encode = new BCryptPasswordEncoder();
        List<Security> list = securityMapper.selectList(null);
        for (Security security : list) {
            auth.inMemoryAuthentication().passwordEncoder(encode)
                .withUser(security.getUser()).password(security.getPasswd())
                .roles(security.getRole());
        }
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        // super.configure(http);
        http.authorizeRequests()
            .antMatchers("/").permitAll()
            .antMatchers("/log_in/**").permitAll()
            .antMatchers("/getPages/**").permitAll()
            .antMatchers("/getData/**").permitAll()
            .antMatchers("/CqnuStu/**").permitAll()
            .antMatchers("/Teacher/**").hasRole("vip")
            .anyRequest().authenticated();

        http.formLogin().loginPage("/log_in").permitAll()
            .usernameParameter("user").passwordParameter("passwd")
            .defaultSuccessUrl("/")
            .failureUrl("/log_in?error");

        http.rememberMe().rememberMeParameter("remember")
            .tokenValiditySeconds(200);

        http.httpBasic();
    }
}
