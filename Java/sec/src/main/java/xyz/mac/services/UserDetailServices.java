package xyz.mac.services;

// @Service
// public class UserDetailServices implements UserDetailsService{

//     @Autowired
//     private UserInfoMapper userInfo;

//     @Autowired
//     private AuthorityMapper authorityMapper;

//     @Override
//     public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
//         UserInfos user = userInfo.selectByName(username);
//         List<Authority> auth = authorityMapper.findAuthoritiesByUsername(username);
//         List<SimpleGrantedAuthority> list = auth.stream().map(a -> new SimpleGrantedAuthority(a.getAuthority())).collect(Collectors.toList());
//         if (user != null) {
//             UserDetails userDetails = new User(user.getUser(), user.getPasswd(), list);
//             return userDetails;
//         } else {
//             throw new UsernameNotFoundException("用户名不存在");
//         }
//     }
    
// }
