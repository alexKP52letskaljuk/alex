package lab2;


class StudentLL {
    private SLLNode head;
    private SLLNode tail;
    private int size;

    public StudentLL() {
        head = new SLLNode(null, null, null);
        tail = new SLLNode(null, null, null);
        head.next = tail;
        tail.prev = head;
        this.size = 0;
    }

    public void clear(){
        head.next = tail;
        tail.prev = head;
        size = 0;
    }

    public int size(){
        return size;
    }

    public SLLNode getHead() {
        return head;
    }

    public SLLNode getTail() {
        return tail;
    }

    public Student removeNode(SLLNode node){
        size--;
        node.prev.next = node.next;
        node.next.prev = node.prev;
        return node.data;
    }


    public void addAfter(SLLNode node, Student s){
        SLLNode newNode = new SLLNode(s,node,node.next);
        node.next.prev = newNode;
        node.next = newNode;
        size++;
    }

    public void addFirst(Student s){
        addAfter(head,s);
    }
    public void addLast(Student s){
        addAfter(tail.prev,s);
    }
}