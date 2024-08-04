# D++ 语言文档

这是D++的源码文档，包括编译器实现，虚拟机实现等

## 编译器实现

### DbgInfos结构

DbgInfos结构用于存储调试信息，包括对象位置，以及对象类型数据等信息

object: Object => 对象数据位置

metadata: std::any[METADATA_MAX] => 对象类型数据

#### DbgInfos::metadata

metadata是一个std::any类型的数组，用于存储对象类型数据。

##### Class Metadata