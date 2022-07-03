## Mock test
* It is basically a way to isolate our tests by __removing the dependencies and replacing them with empty objects.__
* However we'll have full control of these objects.
* Moking is a type of test double that usually means replacing a real object with fake one.
* It's used to isolate the class under the test from its dependencies.

</br>

* Mocking is usually done by extending a class and mocking some of its methods.
* Mocks are particularly useful beacause they can track the calls to themselves.
    * So you can check that the methods was called or not with what parameters.
* Other tpyes of test doubles include __fakes__.
    * They do have a working implementation, but they take shortcuts.
    * They are not suitable for production.
* __Stubs__ are test doubles that respond with predefined data.
    * They don't work outside the test.
    * For example, it could be if we are replacing a real server with a minimal one that responds with predefined data.
* __Mock__ can also respond with predefined data.
    * but they can also have expectations that a certain method to be called, and exception to be thrown and so on.

</br>

### Mocking method
* The way to mock a mothod is by extending a class and redefining the methods that you want to override.
    * You just use the __MOCK_METHOD__ macro.
    * First type is return type of the function.
    * Second is function name, and then coms the list of arguments.
    * example) __MOCK_METHOD(int, Sum, (int, int));__
    * There's one more parameter to this macro, which is optional, such as __const, override, noexcept__.
    * example) __MOCK_METHOD(void, DoSomething, (), (const));__

</br>

* Legacy method
    * Method with __n__ parameters.
    * such as __MOCK_METHOD2(Sum, int(int,int))__
    * If we wanted to mock a const method, we had to use __MOCK_CONST_METHOD__.

</br>

### Setting Expectations & Behavior
* __EXPECT_CALL__ = __ON_CALL__ + expectations
    * ON_CALL: sets the behavior when a method gets called.
    * If what does not meet those expections, it will fail.
* Examples
    * Check the number of calls: EXPECT_CALL(SomeObject, SomeMethod).Times(2)
    * Check the argument: EXPECT_CALL(SomeObject, SomeMethod("Value I expect to be passed"))

</br>

* Setting a certain behavior, we can use the __ACTION__ macro to define an action.
    * Example
``` c++
ACTION(ThrowSomeException){
    throw std::runtime_error("Dummy error");
}
EXPECT_CALL(object, SomeMethod()).WillOnce(ThrowSomeException());

```
* We can configure action/return value as:
    * WillOnce
    * WillRepeatedly
    * WillByDefault
    * Return
    * ReturnRef

</br>

* Expected number of calls:
    * AnyNumber() : We don't care how many times the method was called
    * AtLeast(n), AtMost(n), Between(m, n)
    * Exactly(n) or n

</br>

### Matchers
* __Matchers__ makes our tests broader and more complex restraints.
    * such as Gt(Greater), Ge(Greater or equal), Lt(lower), Le(lower or equal), Eq(equal)
    * **_** matchers for anything that we don't care about the value.
    * IsNull(), IsNotNull() is used for checking against null.
    * String matchers like HasSubstr() is used for string matches.
* Matchers also can be combined by using AllOf(), AnyOf(), AllOfArray(), AnyOfArray() and so on.


</br>

### __[Mock test example](./mock_test.cc)__

</br>

#### Reference: Beginning Test Driven Development (TDD) in C++ with Googletest and Googlemock