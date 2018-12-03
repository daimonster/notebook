spring中的页面跳转也是在controller层中实现的：
```
@Controller
@RequestMapping(value = "/shopadmin",method = {RequestMethod.GET})
public class ShopAdminController {
    @RequestMapping(value = "/shopoperation")
    public String shopOperation(){
        return "shop/shopoperation";
    }

    @RequestMapping(value = "/shoplist")
    public String shopList(){
        return "shop/shoplist";
    }

    ...
}
```
至于为什么是`shop/shoplist`这是在spring-web.xml文件中实现的.