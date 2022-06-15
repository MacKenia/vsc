package xyz.mac.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;

import xyz.mac.model.Authority;

@Mapper
public interface AuthorityMapper extends BaseMapper<Authority> {
    @Select(value = "select a.* from t_user c,t_authority a,t_customer_authority ca where ca.customer_id=c.id and ca.authority_id=a.id and c.user =#{username}")
    public List<Authority> findAuthoritiesByUsername(String username);
}
