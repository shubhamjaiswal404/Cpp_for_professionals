public class MyTestJNI {

    static { System.loadLibrary("mytest"); }            // <- libmytest.so (Linux) at runtime
    private native String CppMethod(String message);    // <- This method from C++ library libmytest.so

    private java.lang.String javaMethod(java.lang.String message)
    {
        System.out.print(message);
        System.out.print(" <-- Output from MyTestJNI.javaMethod() \n");

        java.lang.String rtn = "Return Message From javaMethod";
        return rtn;
    }

    public static void main(String[] args)
    {
        MyTestJNI myObj = new MyTestJNI();  // Create a new instance

        System.out.print("----- Start Java MyTestJNI class ------\n");

        String javaFuncRtn = myObj.javaMethod("Message from MyTestJNI Main for javaMethod");
        System.out.print(javaFuncRtn);
        System.out.print(" <-- Output from MyTestJNI.main()\n");

        String cppFuncRtn = myObj.CppMethod("Message from MyTestJNI Main for CppMethod");
        System.out.print(cppFuncRtn);
        System.out.print(" <-- Output from MyTestJNI.main() \n" );

        System.out.print(cppFuncRtn);
        System.out.print(" <-- Output from MyTestJNI.main() Second time \n" );


    }

}
