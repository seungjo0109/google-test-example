## Unit test
* When we create a new piece of software, we always have to check that we don't break the old code.
* But, we can't do check code manually if project is big. So, we need this for automated.
* As the name suggests, unit tests is testing only one unit of code.
* Unit tests are useful for __regression testing__, meaning that when you make a change, they help prevent the introduction of new bugs. 

</br>

### Characteristics of unit test
1.  Unit test have to be able to excute independently.
    * So, it is very careful __when using global variables or static methods.__
2. They can run quickly at the order of milliseconds.
3. Isolated entity
    * unit test does not rely on any external input, such as waiting for the user to hit the key or networks.

</br>

### Unit test structure
* AAA: Arrange - Act - Assert(optionally cleanup phase included)
* Arrange section is test setup 
    * this is where we set all the inputs and preconditions, create the objects that you need for the test.
* Act section is calling the method or function that you want to test.
* Assert section is checking the obtained results are correct.

</br>

* Advantages of AAA structure:
    * the code under the test is clearly seperated from the setup steps and to the result verification steps.
    * it makes some code quality problems more obvious.

</br>

### Assertion results
* Assertions can have two possible outcomes, __Success or Failure.__
* In case of failure, it has two types of failure, __Fatal, Non-Fatal.__
* Fatal assertions start with ASSERT_, such as ASSERT_EQ, ASSERT_NE, ASSERT_LT, ASSERT_LE, ASSERT_GT, ASSERT_GE.
* non-fatal assertions start with EXPECT_, such as EXPECT_TRUE, EXPECT_FALSE.

</br>

### Assertions on exceptions
* How do you test that the function did or did not throw an exception in the given scenario?
* There are _THROW, _ANY_THROW, _NO_THROW such as ASSERT_THROW, ASSERT_ANY_THROW, ASSERT_NO_THROW.
    * _THROW thorws exception of an exact type.
    * _ANY_THROW throws an exception of any type.
    * _NO_THROW throws no exception.

</br>

### Test Fixture
* Test fixture help you write the test by reusing the code in the setup and in the tear down phase.
* There are very suited for cases when that setup or the test clean up are similar.
* __The fixture is class derived from the _Test_ class in the _testing_ namespace.__
    * There is some special functions we can override. 
    * such as SetUp(), which is called before each test.
    * TearDown(), which is called after each test.
    * SetupTestCase(), which is called before and after the entire suit.
* To create a test fixture, we have to use __TEST_F__.

</br>

### Test Fixtrue flow
* Fixture flow: Constructor -> SetUp -> Test Body -> TearDown -> Destructor.
* It's preferred to use the constructor, destructor because we can make our attribues _const_.
* If we need subclass our fixture, it's preferred to use the constructor or destructor.
    * This is because we may forget to explicitly called in SetUp(), TearDown().

</br>

* We may still use SetUp(), TearDown() when we intend to call virtual methods.
    * If we call a virtual method in the constructor, it is not polymorphic.
* It's not possible to use _fatal assertions_ in constructors.
* Do not call _code that can throw exceptions_ in the desturctor.

</br>

## Parameterized tests
* Parameterized tests are useful when the test body is the same and just inputs are different.
* Parameterized tests are created by extending the test with __TestWithParam<T>__. 
* Test body is deined by using the __TEST_P__.
* We can use various input type by using __Generators, such as Range, Values, ValuesIn, Bool, Combine.__

</br>

### __[Unit test example](./unit_test.cc)__
### __[Test fixture example](./test_fixture.cc)__
### __[Parameterized test example](./parameterized_test.cc)__

</br>

#### Reference: Beginning Test Driven Development (TDD) in C++ with Googletest and Googlemock