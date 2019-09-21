package ListInterface;


public interface IList {
	public IList add(int value);
	public void show();
	public void remove(int position);
	
	public int get(int position);

	public boolean isEmpty();
	public boolean hasValue(int value);
	
	public int getSize();
	
	
}
