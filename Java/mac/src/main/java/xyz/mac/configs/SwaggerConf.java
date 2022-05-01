package xyz.mac.configs;


import org.springframework.context.annotation.Configuration;

@Configuration
// @EnableSwagger2
public class SwaggerConf {
    // public Docket createRestApi() {
    //     return new Docket(DocumentationType.SWAGGER_2)
    //             // 指定构建api文档的详细信息的方法：apiInfo()
    //             .apiInfo(apiInfo())
    //             .select()
    //             // 指定要生成api接口的包路径
    //             .apis(RequestHandlerSelectors.basePackage("xyz.mac.controllers"))
    //             //使用了 @ApiOperation 注解的方法生成api接口文档
    //             //.apis(RequestHandlerSelectors.withMethodAnnotation(ApiOperation.class))
    //             .paths(PathSelectors.any())
    //             //可以根据url路径设置哪些请求加入文档，忽略哪些请求
    //             .build();
    // }

    // /**
    //  * 设置api文档的详细信息
    //  */
    // private ApiInfo apiInfo() {
    //     return new ApiInfoBuilder()
    //             // 标题
    //             .title("Spring Boot集成Swagger2")
    //             // 接口描述
    //             .description("swagger")
    //             // 版本信息
    //             .version("1.0")
    //             // 构建
    //             .build();
    // }
}
