# Object Oriented Programming

It is a programming style which revolve around objects.
Object is an entity which has some state or property and behaviour.  
Due to OOPs, readibility, manageability and extendibility increases.

<h2>Class</h2>  
It is an user defined data type.

If we create an object of empty class then 1 byte of memory will be allocated to keep its identification. If in that class, a variable of datatype int is created then size of that object will be 4 bytes.

All the data members which are `private` can be accessed inside class only.  
Private data members can be accessed or modified by `getter` and `setter` function.

`Padding and greedy Alignment`

**Padding:** Since a processor access a word at a time not a byte at a time. So, lets consider a case like

<pre>
struct stud{  
    char a;  
    char b;  
    int c;  
}  
</pre>

Size of this struct should be 6bytes. But actually its size is 8 bytes.  
Lets consider the word size is 4 bytes. Then in one clock cycle CPU access 1-byte for char a, 1-byte for char b and 2 bytes of int c. To access complete 4-bytes of int c, it need 2 clock cycles. Which wastes the clock cycles. Hence padding comes in picture. It pad as:

<pre>
    -------------------------------------
    | char a | char b| empty |   int c  |
    -------------------------------------
    <----4-bytes-------------><-4-bytes->
</pre>

Now we can access int in one clock cycle.

Eg:

<pre>
    struct stud{
        char a;
        int b;
        char c;
    }
</pre>

Now this struct size is 12 bytes.

1. Static Allocation of object. Data members can be accessed using dot operator.
2. Dynamic Allocation of object. Data members can be accessed either using \* and dot operator or using arrow operator.

<h2>Constructor</h2>

When you create an object then its constructor is called.  
Properties of constructor:

1. Invoked during object creation.
2. No return type
3. No input parameter required. (optional )

Every class has a default constructor. We can create our own constructor for some class.

Let Class name is `Hero`. We created an object of `Hero` class as `H`. By default constructor `H.Hero()` is called. Although `Hero()` is not any method in class.  
We can create our own constructor with same name as name of class.

<pre>
Class Hero{
    public:
    Hero(){
        cout<<"Constructor of class Hero";
    }
};
</pre>

See the code [Here](constructor.cpp)

After writing our own constructor, default constructor is vanished.

<h2>this variable</h2>

`this` is a pointer that points to current object.  
See the code [Here](this.cpp)

<h3>Parameterized Constructor</h3 >

See the code [Here](constructor.cpp)

## Copy Constructor

This is use to copy the data members of one object to another object.
When we create object using copy constructor then only copy constructor will be called. No other constructor like default constructor or user-defined parameterized constructor will be called.

> > Inbuild copy constructor will be generated.

### User-defined Copy constructor

```
Hero(Hero& H){
    this->dataMember1 = H.dataMember1;
    this->dataMember2 = H.dataMember2;
}
```

> > Here `pass by reference ` is used because if we pass by value then H will be copy of parameter passed and to copy it will call the copy constructor and in this way it will stuck into infinite loop.
> > After you define your own copy constructor, default copy constructor will get vanished.

## Deep and Shallow Copy

If we use the defalut copy constructor, then if there is any data member which is a pointer then that address will be copied into new object's data member. Now, any change in that variable in object 1 will also be reflected in object 2. This is a shallow copying. Default copy constructor will do shallow copying.

In case deep copy, we create new pointer of same data type and copy information located at first pointer in memory pointed by second pointer. Now, allocate this new pointer to data member.

## Copy Asignment operator:

It copies the data member of one object into data member of another object.

## Destructor

1. Called at the end of the program.
2. No return type.
3. No input parameters
4. Name of destructor start with `~` sign followed by name of class.

> > For static allocation of object, destructor is called automatically. But for dynamic allocation we have call destructor manually.  
> > See the code [Here](destructor.cpp)

## Static Data type

> > Data members defined with static keyword belong to class only and don't need object to access. It will always have the same value for all the objects of that class.  
> > Static data members cannot be created inside class. We initilize static data members outside the class as:

```
datatype of static data member ClassName::static_name = value;

int Hero::timeToComplete = 5;
```

We can access and modify static data members using object also but not recommended.  
Can be accessed in main using scope resolution operator.

```
cout<<Hero::timeToComplete<<endl;
```

## Static functions:

Properties:

1. No need of object creation to access these functions.
2. It `don't` have any `this` keyword. Since `this` keyword is pointer to current object and static functions don't have objects.
3. Static functions can access only static data members.

See the code [Here](static.cpp)

## Encapsulation:

Wrapping up of data members and methods.  
We put the data members and methods in a class. Here Class act like a capsule for data members and methods.

> > ### Fully Encapsulated Class:
> >
> > Class where all the data members are private data members.

Main motive of encapsulation is data Hiding/information hiding.

> > ### Advantage of Encapsulation:
> >
> > 1.  Since it hide data, hence security increases.
> > 2.  We can make our class "Read Only". By keeping all data members private and writing only getter method not setter method.
> > 3.  Code reuseability.
> > 4.  Encapsulated code is better for unit testing.

## Inheritence:

Lets say that Class B inherit Class A. Then Class A is parent class or super class and Class B is subclass or child class.

Syntax:

```
class parent_class{
    //This is parent class.
};

class child_class:access_modifier parent_class {
    This is child class of parent_class.
};

access_modifiers(mode of inheritence) are: public, private, protected.
```

Role of 'mode of inheritence':
Since data members of parent class have some access modifiers. Now on the basis of mode of inheritence, we can set the access modifiers of data members of parent class in child class.

```
                public      protected       private
public          public      protected       private
protected       protected   protected       private
private      Not Accessible  NA             NA
```

## Protected Aceess modifier:

You can access the protected data members inside that class as well as in child class. But not outside the main or derived class.

> > If a data member is marked `private` in parent class then that data member is not accessible in child class.

### Types of Inheritence:

1. Single Inheritence
2. Multilevel Inheritence

```
This inheritence is like class B inherit class A and class C inherit class B.
```

> > 3. Multiple Inheritence:  
> >    Inheriting multiple classes in a single class.
> >
> > ```
> > class C: public A, public B{
> >    This is multiple inheritence.
> > }
> > ```

4. Hierarchical Inheritence:  
   When a parent class have more than one child class.
5. Hybrid Inheritence:  
   Combining two or more type of inheritence.

## Inheritence Ambiguity:

> > 1. If child as well as parent class have same method or data member then object of child class will access the method or data member of child class only.
> >    See the code [Here](inheritenceAmbiguity1.cpp)
> > 2. If two classes have same function and third class inherit those two classes then it will be ambiguous. To avoid this we use scope resolution operator as:
> >
> > ```
> > If you want to use function of A in class C use as:
> > obj.A::func1()
> > ```
> >
> > See the code [Here](inheritenceAmbiguity2.cpp)

## Polymorphism:

Polymorphism is derived from two words one is poly which means `many` and other is morph which means `forms`.
When something exit multiple forms then is polymorphism.

Two types of polymorphism:

1. Compile time polymorphism. (static polymorphism)
2. Run time polymorphism. (Dynamic polymorphism)

## Compile time polymorphism:

When in compile time we know that which entity exist in which forms.
It has two types:

1. Function overloading.
2. Operator overloading.

### Function overloading:

If there are multiple functions of same name then that should be differ by their data type of parameters or number of parameters.

> > Function which differs only by their return type cannot be overloaded.

### Operator overloading:

When we want to change the behaviour of operator.

```
Lets we want to change the behaviour of + operator as instead of adding it start subtracting.

syntax:
return type operator<name of operator> (class name &obj){

}

in case of a+b , b is input parameter and a belong to current object (can be accessed using this operator).
```

### Operators that cannot be overloaded:

> > 1. ? “.” Member access or dot operator.
> > 2. ? “? : ” Ternary or conditional operator.
> > 3. ? “::” Scope resolution operator.
> > 4. ? “. \*” Pointer to member operator.
> > 5. ? “ sizeof” The object size operator.
> > 6. ? “ typeid” Object type operator.

See the code [Here](operatorOverloading.cpp)

### Run time polymorphism

In the run time we get to know that some entity exist in mulitple forms.
Method overriding is a way to implement run time polymorphism.

### Method overriding:

Method overriding is a feature which allows you to redefine method of parent class in method of child class.
In other words, whatever method parent class have must also be present in child class. But sometime child class is not satisfied by method implementation in parent class so it redefine that method in child class according to its own requirement.

#### Rulse of Method overriding:

> > 1. Method of parent class and method of child class must have same name.
> > 2. Method of both classes have same parameters.
> > 3. It is possible through inheritence only.

See the code [Here](methodOverriding.cpp)

## Abstraction

This is also known as implementation hiding. This is used when we don't want to show implementation to outside world.

We can achieve abstraction using:

> > 1. Access specifiers. Which data members we need to keep public and which to keep private.
> > 2. Abstraction using header files.

### Advantage of abstraction:

1. Only you can modify.
2. Makes application secure by not allowing anyone else to see the background details.
3. Increase the reuseability of code.
4. Avoids duplication of code.
