public class MyTestJNI {

    static { System.loadLibrary("mytest"); }    // <- libmytest.so (Linux) at runtime
    private native String CppMethod(String message); // <- This method from C++ library libmytest.so


    private java.lang.String value ;
    private void setValue(java.lang.String val)
    {
        value = val;
        System.out.print(val);
        System.out.print( " <-- MyTestJNI.setValue() \n" );
    }


    public static void main(String[] args)
    {
        MyTestJNI myObj = new MyTestJNI();  // Create a new instance

        System.out.print("----- Start Java MyTestJNI class ------\n");

        /*
        myObj.setValue("Hello From MyTestJNI.main()");
        System.out.print(myObj.value);
        System.out.print(" <-- MyTestJNI.main() \n");
        */

        String cppFuncRtn = myObj.CppMethod("Hello from MyTestJNI Main for CppMethod");
        System.out.print(cppFuncRtn);
        System.out.print(" <--  MyTestJNI.main() \n" );

        System.out.print(myObj.value);
        System.out.print(" <--  MyTestJNI.main() \n" );

    }

}












