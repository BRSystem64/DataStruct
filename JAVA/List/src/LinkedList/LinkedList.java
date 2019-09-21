package LinkedList;

public class LinkedList implements ListInterface.IList {

	Node head;
	int size;
	
	public LinkedList(){
		this.head = null;
		this.size = 0;
	}
	
	@Override
	public LinkedList add(int value) {		
		if(!isEmpty()) {
			Node aux = head;
			while(aux.getNext() != null) {
				aux = aux.getNext();
			}
			aux.setNext(new Node(value));
		}else {
			head = new Node(value);
		}
		size++;
		return this;
	}

	@Override
	public void show() {
		if(!isEmpty()) {
			Node aux = head;
			while(aux != null) {
				System.out.print("|"+ aux.getValue() + "|->");
				aux = aux.getNext();
			}
			System.out.print(" NULL ");
		}	
	}

	@Override
	public void remove(int position) {
		if(!isEmpty() && position < getSize()) {
			if(position == 0) {
				head = head.getNext();
				size--;
			}else if(position > 0) {
				Node aux = head;
				while(position > 1) {
					aux = aux.getNext();
					position--;
				}
				aux.setNext(aux.getNext().getNext());
				size--;
			}
		}
	}

	@Override
	public int get(int position) {
		if(!isEmpty() && position < getSize() && position >= 0) {
			Node aux = head;
			while(position > 0) {
				aux = aux.getNext();
				position--;
			}
			return aux.getValue();
		}
		return -999999;
	}

	@Override
	public boolean isEmpty() {
		return getSize() == 0 ? true : false;
	}

	@Override
	public boolean hasValue(int value) {
		if(!isEmpty()) {
			Node aux = head;
			for(int p =0; p < getSize(); p++) {
				if(aux.getValue() == value) {
					return true;
				}
				aux = aux.getNext();
			}
		}
		return false;
	}

	@Override
	public int getSize() {
		return this.size;
	}

}
