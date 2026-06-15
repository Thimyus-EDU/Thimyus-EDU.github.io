package task;
import java.util.HashMap;

public class TaskService {
	private final HashMap<String, Task> taskList = new HashMap<>();
	
	public void addTask(Task task) {
		taskList.put(task.getId(), task);
	}
	
	public void deleteTask(Task task) {
		taskList.remove(task.getId());
	}
	public void updateTask(String id, String name, String description) {
		if(!taskList.containsKey(id)) {
			throw new IllegalArgumentException("This task is not in the list.");
		}
		
		Task taskToUpdate = taskList.get(id);
		
		String updatedTaskName = (name != null) ? name : taskToUpdate.getName();
		String updatedTaskDescription = (description != null) ? description : taskToUpdate.getDescription();
		
		Task updatedTask = new Task(id, updatedTaskName, updatedTaskDescription);
		
		taskList.put(id, updatedTask);
	}
	
	public Task getTask(String id) {
		return taskList.get(id);
	}
}
