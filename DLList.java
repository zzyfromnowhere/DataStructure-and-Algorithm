import java.lang.classfile.attribute.InnerClassesAttribute;

public class DLList {
    private IntNode sentinel;
    private int size;

    private static class IntNode{
        IntNode last;
        int item;
        IntNode next;

        public IntNode(IntNode l,int x, IntNode n){
            this.last = l;
            this.item = x;
            this.next = n;
        }

        public int get(){
            return item;
        }
    }

    //constructor with parameters
    public DLList(int x){
        this.sentinel = new IntNode(null, 63, null);
        IntNode first = new IntNode(sentinel, x, sentinel);
        sentinel.next = first;
        sentinel.last = first;
        this.size = 1;
    }
    //constructor without parameter
    public DLList(){
        this.sentinel = new IntNode(null, 63, null);
        this.sentinel.last = sentinel;
        this.sentinel.next = sentinel;
        this.size = 0;
    }

    //add x to the front of the list
    public void addFirst(int x){
        IntNode first = new IntNode(sentinel, x, sentinel.next);
        sentinel.next.last = first;
        sentinel.next = first;
        this.size ++;
    }
    //add x to the last of the list
    public void addLast(int x){
        IntNode last = new IntNode(sentinel.last, x, sentinel);
        sentinel.last.next = last;
        sentinel.last = last;
        this.size++;
    }

    //returns the first item of the list
    public int getFirst(){
        if(sentinel.next == sentinel){
            System.out.print("The list is empty!");
            return -1;
        }
        return sentinel.next.item;
    }
    //returns the last item of the list
    public int getLast(){
        if(sentinel.last == sentinel){
            System.out.println("The list is empty!");
            return -1;
        }
        return sentinel.last.item;
    }

    //removes the first of the list
    public void removeFirst(){
        if(sentinel.next == sentinel){
            System.out.println("The list is empty!");
            return;
        }
        IntNode r = sentinel.next;
        sentinel.next = r.next;
        sentinel.next.last = sentinel;
        this.size --;
    }
    //removes the last of the list
    public void removeLast(){
        if(sentinel.last == sentinel){
            System.out.println("The list is empty!");
            return;
        }
        IntNode r = sentinel.last;
        sentinel.last = r.last;
        sentinel.last.next = sentinel;
        this.size --;
    }
    //removes the ith node of the list
    public void remove(int i){
        if(i >= this.size){
            System.out.println("ERROR! Your index is larger than the size of the list!");
            return;
        }
        IntNode p = sentinel;
        while(i != 0){
            i--;
            p = p.next;
        }
        IntNode r = p.next;
        p.next = r.next;
        r.next.last = p;
    }

    //return the size of the list
    public int size(){
        return this.size;
    }

    //print all the items in the list
    public void printList(){
        IntNode p = this.sentinel.next;
        while(p != sentinel){
            System.out.print(p.item + " ");
            p = p.next;
        }
    }

    //returns the ith item of the list
    public int get(int i){
        if(i >= this.size){
            System.out.println("ERROR!Your index is larger than the size of the list!");
            return -1;
        }
        IntNode p = sentinel.next;
        while(i != 0){
            i--;
            p = p.next;
        }
        return p.item;
    }




















}
