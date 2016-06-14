package lab2;


class SLLNode{
    Student data;
    SLLNode next;
    SLLNode prev;

    public SLLNode(Student data, SLLNode prev, SLLNode next) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
}

