### 定义
```
HashMap<Character,Integer> map=new HashMap<Character,Integer>();
```

### 判断包含key
```
map.containsKey(c)
```

### 通过key得到值
```
map.get(c)
```

### 放入键值对
```
map.put(c,time);
```

### 遍历方式
```
Map map = new HashMap();
Iterator iter = map.entrySet().iterator();
while (iter.hasNext()) {
    Map.Entry entry = (Map.Entry) iter.next();
    Object key = entry.getKey();
    Object val = entry.getValue();
}
```