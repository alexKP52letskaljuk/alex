package lab1;


public class Lab1 {
    public static void ensure(boolean s){
        if(!s) System.out.println("ERROR!");
    }

    public static void queueTest(){
        System.out.println("====== Queue tests =======");
        Queue q = new Queue(3);
        q.add("1");
        q.add("2");
        q.add("3");
        System.out.println(q);//[1 2 3]
        ensure(q.remove().equals("1"));//[2 3]
        q.add("4");//[2 3 4]
        ensure(q.remove().equals("2"));//[3 4]
        System.out.println(q);//[3 4]
        ensure(q.remove().equals("3"));//[4]
        ensure(q.remove().equals("4"));//[]
        q.add("5");//[5]
        ensure(q.remove().equals("5"));//[]
    }

    public static void stackTest(){
        System.out.println("====== Stack tests =======");
        Name[] names = {
                Name.Kolya,
                Name.Masha,
                Name.Lyosha,
                Name.Dasha,
                Name.Vlad,
                Name.Natasha,
                Name.Dima,
                Name.Katya,
                Name.Sergei,
                Name.Lena};
        Stack s = new Stack();
        for(int i =  0; i < names.length; i++)
            s.push(names[i]);
        for(int i = names.length - 1; i >= 0; i--)
            ensure(s.pop() == names[i]);

        s.push(Name.Dima);
        s.push(Name.Katya);
        s.push(Name.Lyosha);
        s.push(Name.Lena);
        System.out.println(s);
        s.pop();
        s.pop();
        System.out.println(s);
    }

    public static void task3(){
        System.out.println("========= Task 3 =========");
        Stack stack = new Stack();
        Queue maleQueue = new Queue();
        Queue femaleQueue = new Queue();

        Name[] names = {
                Name.Kolya,
                Name.Masha,
                Name.Lyosha,
                Name.Dasha,
                Name.Vlad,
                Name.Natasha,
                Name.Dima,
                Name.Katya,
                Name.Sergei,
                Name.Lena};
        for(int i = 0; i < names.length; i++) 
        	stack.push(names[i]);
        while(stack.size() > 0){
            Name n = stack.pop();
            if(n.isMale()) maleQueue.add(n.toString());
            else femaleQueue.add(n.toString());
        }
        System.out.println("Male queue: "+maleQueue);
        System.out.println("Female queue: "+femaleQueue);
    }

    public static void main(String[] args){
        queueTest();
        stackTest();
        task3();
    }
}