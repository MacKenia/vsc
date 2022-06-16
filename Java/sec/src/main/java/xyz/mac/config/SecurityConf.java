package xyz.mac.config;

// @Configuration
// @EnableWebSecurity
// public class SecurityConf extends WebSecurityConfigurerAdapter{
    
//     @Autowired
//     private UserDetailServices userDetailServices;

//     @Resource
//     private DataSource dataSource;

//     @Override
//     public void configure(AuthenticationManagerBuilder auth) throws Exception {
//         BCryptPasswordEncoder encoder = new BCryptPasswordEncoder();
//         auth.userDetailsService(userDetailServices).passwordEncoder(encoder);
//     }

//     @Override
//     public void configure(HttpSecurity http) throws Exception {
//         http.authorizeRequests()
//             .antMatchers("/").permitAll()
//             .antMatchers("/login/**").permitAll()
//             .antMatchers("/detail/common/**").hasAnyRole("common","vip")
//             .antMatchers("detail/vip/**").hasRole("vip")
//             .anyRequest().authenticated();

//         http.formLogin().loginPage("/login")
//             .usernameParameter("user").passwordParameter("passwd")
//             .defaultSuccessUrl("/")
//             .failureUrl("/login?error");

//         http.logout().logoutUrl("/logout").logoutSuccessUrl("/");

//         http.rememberMe().rememberMeParameter("remember")
//             .tokenRepository(tokenRepository());
        
//         http.csrf().disable();

//     }

//     @Bean
//     public JdbcTokenRepositoryImpl tokenRepository() {
//         JdbcTokenRepositoryImpl tokenRepository = new JdbcTokenRepositoryImpl();
//         tokenRepository.setDataSource(dataSource);
//         return tokenRepository;
//     }
    
// }
