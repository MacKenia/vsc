package xyz.mac.configs;

// @EnableWebSecurity
// public class SecurityConf extends WebSecurityConfigurerAdapter{
//     @Override
//     protected void configure(AuthenticationManagerBuilder auth) throws Exception{
//         BCryptPasswordEncoder encode = new BCryptPasswordEncoder();
//         auth.inMemoryAuthentication().passwordEncoder(encode)
//             .withUser("fuck").password(encode.encode("123456")).roles("common")
//             .and()
//             .withUser("mike").password(encode.encode("123321")).roles("common")
//             .and()
//             .withUser("admin").password(encode.encode("666666")).roles("vip");
//     }

//     @Override
//     protected void configure(HttpSecurity http) throws Exception {
//         super.configure(http);
//     }
// }
