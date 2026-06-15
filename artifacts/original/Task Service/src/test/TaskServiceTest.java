package test;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import task.Task;
import task.TaskService;

public class TaskServiceTest {
	private Task task;
	private TaskService taskService;
	
	@BeforeEach
	void testSetUp() {
		taskService = new TaskService();
		task = new Task("001", "Test Task", "This is a task description");
		taskService.addTask(task);
	}
	
	@Test
	void testAddTaskMethod() {
		try {
			taskService.updateTask("001", "New Task", "This is a new task");
		} catch (Exception e) {
			fail("Exception was thrown: " + e.getMessage());
		}
	}
	
	@Test
	void testDeleteTaskMethod() {
		taskService.deleteTask(task);
		Exception exception = assertThrows(IllegalArgumentException.class, () -> {
			taskService.updateTask("001", "New Task", "This is a new task");
		});
		assertEquals("This task is not in the list.", exception.getMessage());
	}
	
	@Test
	void testUpdateTaskMethod() {
		try {
			taskService.updateTask("001", "New Task", "This is a task description");
		} catch (Exception e) {
			fail("Task name update threw an exception: " + e.getMessage());
		}
		
		Task updatedTask = taskService.getTask("001");
		assertEquals("New Task", updatedTask.getName());
	}
	
	@Test
	void testUpdatingNonExistingTask() {
		Exception exception = assertThrows(IllegalArgumentException.class, () -> {
			taskService.updateTask("0001", "New Task", "This is a new task");
		});
		assertEquals("This task is not in the list.", exception.getMessage());
	}
}
