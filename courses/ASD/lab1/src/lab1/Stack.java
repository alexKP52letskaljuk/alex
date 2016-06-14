package lab1;

public class Stack {
    private static class Node{
        Name data;
        Node prev;

        public Node(Name data) {
            this.data = data;
        }
    }
    private Node top;
    private int size;

    public Stack(){
        top = new Node(null);
        size = 0;
    }

    public boolean push(Name name){
        if(size % 2 == 1 && name.isMale()) return false;
        if(size % 2 == 0 && !name.isMale()) return false;

        Node newTop = new Node(name);
        newTop.prev = top;
        top = newTop;
        size++;

        return true;
    }

    public Name pop(){
        if(size == 0) return null;

        Name ret = top();
        top = top.prev;
        size--;

        return ret;
    }

    public Name top(){
        return top.data;
    }

    public int size(){
        return size;
    }

    @Override
    public String toString(){
        String names = "";
        Node n = top;
        for(int i = 0; i < size; i++){
            names=n.data.toString()+" " + names;
            n = n.prev;
        }
        return "["+names+"]";
    }
}