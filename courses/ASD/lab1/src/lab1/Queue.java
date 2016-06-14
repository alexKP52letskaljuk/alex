package lab1;

import java.util.Arrays;

public class Queue {
    private String[] data;
    private int tail;
    private int head;
    private int size;

    public Queue(int initialCapacity) {
        if(initialCapacity < 1) initialCapacity = 1;
        data = new String[initialCapacity];
        head = 0;
        tail = 0;
        size = 0;
    }

    public Queue() {
        this(10);
    }

    private void resize() {
        String[] old_data = data;
        data = Arrays.copyOfRange(data, head, head + data.length * 2);
        if (head < tail) {
            tail = tail - head;
        } else {
            int head_els = old_data.length - head;
            System.arraycopy(old_data, 0, data, head_els, tail);
            tail = head_els + tail;
        }
        head = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size==0;
    }

    public void add(String s) {
        if (size == data.length)
            resize();
        data[tail++] = s;
        size++;
        tail %= data.length;
    }

    public String remove() {
        if (size == 0)
            return null;
        else {
            String ret = data[head];
            data[head++] = null;
            size--;
            head %= data.length;
            return ret;
        }
    }
    public String peek() {
        if(size!=0)
            return data[head];
        else return null;
    }

   @Override//ключевое слово,которое позволяет в дочернем классе заново создать реализацию метода родительского класса.
    public String toString(){
        String ret = "[";
        for(int i = head; i < head + size; i++){
            ret+= data[i% data.length] + " ";
        }
        ret+="]";
        return ret;
    }
}

enum Name {
    Masha, Dasha, Natasha, Katya, Lena,
    Kolya, Lyosha, Sergei, Vlad, Dima;

    public boolean isMale(){
        Name[] maleNames = {Kolya, Lyosha, Sergei, Vlad, Dima};
        for(int i = 0; i  < maleNames.length; i++)
            if(maleNames[i] ==this) return true;
        return false;
    }
}