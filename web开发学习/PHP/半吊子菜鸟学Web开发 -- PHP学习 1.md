## 1索引数组

    $fruit = array("苹果"，"香蕉","菠萝")；

    print_r($fruit);

1. 索引数组的初始化，有三种方式：

    * $arry[0] = "苹果";

    * array('0'=>"苹果")；

    * array('苹果')，系统默认从索引0开始

4. 取出索引数组中的值 `$fruit0 = $fruit['0'];`

5. for的使用，for的使用与C类似

5. foreach的使用

```
foreach($fruit as $key=>$value)
{

　　echo '第'.$key.'值是:'.$value;

}
```
***

## 2关联数组

关联数组指的是键是字符串的数组
```
$fruit = array('apple'=>'苹果','orange'=>'橘子')

print_r($fruit);
```

关联数组的创立
```

$arr = array();

$array['apple'] = '苹果'；
```

或者
```

$arr = array('apple'=>"苹果");
```

取关联数组的值
```
$value = $fruit['banana'];

foreach($fruit as $key=>$value);
```
***
## 3PHP中的对象

### 定义一个类
```
class Car {
    var $name = '汽车';
    function getName() {
        return $this->name;
    }
}
$car = new Car();
$car->name = '宝马';
echo $car->getName();
```

同样类中的变量有public,private,protect

PHP在类中使用__construct()定义一个构造函数

```
 class Car {
　　function __construct()
　　{
　　　　 print "构造函数被调用\n";
　　}
　　function __destruct()
　　{
　　　　print "析构函数被调用\n";
　　}
}
```
### 静态属性与方法可以在不实例化类的情况下调用

直接使用类名::方法名的方式进行调用。静态属性不允许对象使用->操作符调用。

静态方法也可以通过变量进行动态调用
```
$func = 'getSpeed';
$classname = 'Car'
echo $className::$func();
```
静态方法不能用this调用，可以用self,parent加上：：来实现

### 方法的重载

属性的重载通过使用__set,__get,__isset,_unset
```
ublic function __set($key, $val) {
        $this->ary[$key] = $val;
    }
    
    public function __get($key) {
        if (isset($this->ary[$key])) {
            return $this->ary[$key];
        }
        return null;
    }
```
如果调用的方法不存在的时候，将会调用__call方法,如果是静态方法，将会调用__callstatic方法


```
public function __call($name, $args) {
        if ($name == 'speedUp') {
            $this->speed += 10;
        }
    }
```
### 类和对象的高级特性

同一个类的两个实例的所有属性都相等时，可以用==来判断
```
$a = new Car();
$b = new Car();
if ($a == $b) echo '=='; 

if ($a === $b) echo '==='; 
```
同一个类的两个变量是否为同一个对象的引用的时候，可以用===来判断

对象的复制，用关键字clone来复制一个对象
```
class Car {
    public $name = 'car';
    
    public function __clone() {
        $obj = new Car();
        $obj->name = $this->name;
    }
}
$a = new Car();
$a->name = 'new car';
$b = clone $a;
var_dump($b);
```
### 对象序列化

可以通过serialize方法将对象序列化为字符串，用于存储或者传递数据，然后在需要的时候通过unserialize将字符串反序列化成对象进行使用。
```
$a = new Car();
$str = serialize($a); //对象序列化成字符串
echo $str.'<br>';
$b = unserialize($str); //反序列化为对象
var_dump($b);
```