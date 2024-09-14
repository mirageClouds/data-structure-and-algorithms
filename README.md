# 学习数据结构与算法

## 二分搜索算法

* 给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。

  * 直接解法：
  
    * ```c
      const int len = sizeof(nums)/sizeof(nums[0]);
      for (int i = 0; i < len; ++i) {
          if (nums[i] == target) return i;
          if (nums[i] > target) return -1;
      }
      ```
  
  * 二分查询解法
  
    * ```c
      int start = 0, end = (int) (numsSize) / 2;
      nums[end] < target ? end = numsSize - 1 : end;
      if (numsSize == 1) end = numsSize - 1;
      while (start <= end) {
          if (nums[start] == target) return start;
          if (nums[end] == target) return end;
          start += 1;
          end -= 1;
      }
      return -1;
      ```
  
  * 递归解法
  
    * ```c
      //递归解法
      int binarySearch(int *arr, int target, int left, int right) {
          if (left > right) return -1;
          int mid = (left + right) / 2;
          if (arr[mid] == target) return mid;
          if (arr[mid] < target)
              return binarySearch(arr, target, mid + 1, right);
          else
              return binarySearch(arr, target, left, mid - 1);
      }
      
      int search(int *nums, int numsSize, int target) {
          //递归解法
          return binarySearch(nums, target, 0, numsSize - 1);
      }
      
      ```

## 线性表

### 顺序表

* 顺序表的创建

  * ```c
    //顺序表
    typedef int E; //给int类型设置别名
    
    //创建构造体
    struct List {
        E *array;
        int size;
        int capacity;
    };
    
    typedef struct List *ArrayList; //对构造体设置别名
    
    // 初始化顺序表
    int initList(ArrayList list) {
        list->capacity = 10;
        //动态规划内存使用量
        list->array = malloc(sizeof(E) * list->capacity);
        // 判断是否动态申请内存成功
        if (list->array == NULL) {
            return 0;
        }
        list->size = 0;
        return 1;
    }
    
    int main(void) {
        struct List list;
        //判断是否成功初始化顺序表
        if (initList(&list)) {
            //成功初始化后的操作
        } else { printf("Error"); }
    }
    ```

* 插入顺序表方法

  * ```c
    // 创建顺序表插入方法
    int insertList(const ArrayList list, const E element, const int index) {
        // 判断index的值是否合法
        if (index < 1 || index > list->size + 1) return 0;
        // 对顺序表进行扩容
        if (list->size == list->capacity) {
            //添加新内存的大小为 原内存大小+原内存大小除以2
            const int newCapacity = list->capacity + (list->capacity >> 1);
            //动态规划新数组的动态内存大小
            E *newArray = realloc(list->array, newCapacity * sizeof(E));
            //判断申请新内存是否成功
            if (newArray == NULL) return 0;
            //调整原构造体内容
            list->array = newArray;
            list->capacity = newCapacity;
        }
    
        //使用for遍历，从末尾开始，将数组每一项数据的值替换为前一项数组的值
        for (int i = list->size; i > index; i--) {
            list->array[i] = list->array[i - 1];
        }
        //对第index项的数据进行替换
        list->array[index - 1] = element;
        //由于数据增加了，size应该也增加
        list->size++;
        return 1;
    }
    ```

* 顺序表删除方法

  * ```c
    //创建数组删除方法
    int deleteList(const ArrayList list, const int index) {
        //判断index是否合法
        if (index < 1 || index > list->size) return 0;
        //使用for遍历，从index开始，将数组前一项的值替换为后一项的值
        for (int i = index - 1; i < list->size - 1; ++i)
            list->array[i] = list->array[i + 1];
        //由于数据减少了,size应该减少
        list->size--;
        return 1;
    }
    ```

* 顺序表打印方法

  * ```c
    //创建打印顺序表方法
    void printList(ArrayList list) {
        for (int i = 0; i < list->size; ++i)
            printf("%d ", list->array[i]);
        printf("\n");
    }
    ```

* 获取顺序表长度

  * ```c
    int sizeList(const ArrayList list) {
        //由于我们有构造体中维护有size,说以说直接把size返回回去,如果没有维护size可以使用sizeof()
        // int len = sizeof(list->array) / sizeof(list->array[0]);
        return list->size;
    }
    ```

* 获取指定位置上的元素

  * ```c
    E * getList(const ArrayList list, const int index) {
        //判断index是否合法
        if (index < 1 || index > list->size) return NULL;
        //因为返回的是指针,所以要对构造体中取出来的数据进行取地址操作
        return &list->array[index - 1];
    }
    ```

* 查询元素在顺序表中的位置

  * ```c
    int findList(const ArrayList list, const E element) {
        for (int i = 0; i < list->size; ++i) {
            // 遍历，若找到了就返回位置
            if (list->array[i] == element) return i+1;
        }
        return -1;
    }
    ```

* main

  * ```c
    int main(void) {
        struct List list;
        //判断是否成功初始化顺序表
        if (initList(&list)) {
            //成功初始化后的操作
            for (int i = 0; i <= 30; ++i) {
                insertList(&list, i * 10, i);
            }
            deleteList(&list, 1);
            printList(&list);
            printf("%d",*getList(&list, 1));
            printf("%d",sizeList(&list));
            printf("%d",findList(&list, 50));
        } else { printf("Error"); }
    }
    ```

### 单链表

* 单链表的创建

  * ```c
    //设置int 的别名 E
    typedef int E;
    
    //E:携带的数据, struct ListNode *next:指向的下一个链表的指针
    struct ListNode {
        E element;
        struct ListNode *next;
    };
    
    //设置结构体别名
    typedef struct ListNode * Node;
    
    //初始化单链表
    void initList(const Node node) {
        node->next = NULL;
    }
    
    nt main(void) {
        struct ListNode head;
        initList(&head);
    }
    ```

* 创建单链表插入方法

  * ```c
    _Bool insertList( Node head, const E element, int index) {
        //判断index是否合法
        if(index<1) return 0;
        //通过--index的方式不断向后寻找前节点
        while(--index) {
            head = head->next;
            if(head == NULL) return 0;
        }
    
        //动态创新新节点
        const Node newNode = malloc(sizeof(struct ListNode));
        //判断节点为空，返回0
        if(newNode == NULL) return 0;
        newNode->element = element;    //把数据赋值给新节点
        newNode->next = head->next;   //把当前数据的指针传递给新节点
        head->next = newNode;   //把新节点的指针赋值给当前节点
    
        return 1;
    }
    ```

* 创建单链表打印方法

  * ```c
    //创建单链表打印方法
    void printList( Node head) {
        while(head->next) {
            head = head->next;
            printf("当前值为%d", head->element);
        }
    }
    ```

* 创建单链表删除方法

  * ```c
    //创建单链表删除方法
    _Bool deleteList(Node head,int index) {
        //判断index是否合法
        if(index<1) return 0;
        //通过--index的方式不断向后寻找前节点
        while(--index) {
            head = head->next;
            if(head == NULL) return 0;
        }
        if(head->next == NULL) return 0;  //判断删除的节点是否存在
        const Node temp = head->next; //拿到待删除的节点
        head->next = head->next->next; //让前节点指向下一个的下一个节点
        free(temp); //使用free函数释放内存
        return 1;
    }
    ```

* 获取指定位置上的元素

  * ```c
    E * getList(Node head,int index) {
        // 判断index是否合法
        if(index<1) return 0;
        //因为不计算头节点，所以使用do-while语句
        do {
            head = head->next;
            if(head == NULL) return 0;
        }while(--index);//到达index结束
        return &head->element;
    }
    ```

* 查询元素在单链表中的位置

  * ```c
    int findList(Node head, const E element) {
        // 定义计数器
        int i = 0;
        do {
            //进入第一个节点
            head = head->next;
            //找到了就返回i，没找到就i++
            if(head->element != element) return i;
            i++;
        }while(head->next);
        return -1;
    }
    ```

* 获取单链表长度

  * ```c
    int sizeList(Node head) {
        int i = -1;
        while(head) {
            head = head->next;
            i++;
        }
        return i;
    }
    ```

* main

  * ```c
    int main(void) {
        struct ListNode head;
        initList(&head);
    
        for(int i = 1; i <= 3; ++i) {
            insertList(&head, i*100, i);
        }
        deleteList(&head, 2);
        printList(&head);
        printf("%d", findList(&head, 100));
    
    }
    ```

### 双向链表

* 双向链表的创建

  * ```c
    typedef int E;
    
    struct ListNode {
        E element;
        struct ListNode *next;
        struct ListNode *prev;
    };
    
    typedef struct ListNode * Node;
    
    //双向链表初始化
    void initList(const Node node) {
        node->next = node->prev = NULL;
    }
    ```

* 双链表插入方法

  * ```c
    //创建双链表插入方法
    _Bool insertList( Node node, const E element, int index) {
        //判断index是否合法
        if(index<1) return 0;
        //遍历找到插入的位置
        while (--index) {
            node = node->next;
            if(node == NULL) return 0;
        }
        // 动态创建内存空间
        const Node new_node = malloc(sizeof(struct ListNode));
        if(node == NULL) return 0; // 判断内存空间是否成功创建
        new_node->element = element;
    
        if(node->next) {
            new_node->next = node->next;    //将新节点的后节点指针替换成当前节点的后指针
            node->next->prev = new_node;    //将当前节点的后节点的前节点的指针指向新节点
        }else {
            new_node ->next = NULL; // 如果当前节点的后节点为空时，新节点的后指针也应当为空
        }
    
        node->next = new_node;  //将当前节点的后指针指向新节点
        new_node->prev = node;  //将新节点的前指针指向当前节点
    
        return 1;
    }
    ```

* 双向链表删除方法

  * ```c
    _Bool deleteList( Node node,int index) {
        // 判断index是否合法
        if(index<1) return 0;
        // 遍历找到需要删除的节点
        while (--index) {
            node = node->next;
            if(node == NULL) return 0;
        }
        // 判断当前节点的后节点是否为空
        if(node->next == NULL) return 0;
    
        //拿到当前节点
        const Node temp = node->next;
        // 判断当前节点的下一个节点的下一个节点是否存在
        if( node->next->next) {
            node->next = node->next->next; //将当前节点的下一个节点替换为当前节点的下一个节点的下一个节点
            node->next->next->prev = node;  //将当前节点的下一个节点的下一个节点的上节点指针指向当前节点
        }else {
            node->next = NULL;  //相当于删除最后一个节点
        }
        free(temp);  //释放内存
        return 1;
    }
    ```

* main

  * ```c
    int main(void) {
        struct ListNode node;
        initList(&node);
    
        for (int i = 0; i < 10; i++) {
            insertList(&node, i*100, i);
        }
    
        deleteList(&node, 4);
        printNextList(&node);
    }
    ```

### 循环链表

​	

