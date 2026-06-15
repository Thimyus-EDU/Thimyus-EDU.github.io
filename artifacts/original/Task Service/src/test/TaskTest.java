package test;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import task.Task;

public class TaskTest {
	@Test
	void testTask() {
		Task task = new Task("001", "Test Task", "This is a test task");
		assertTrue(task.getId().equals("001"));
		assertTrue(task.getName().equals("Test Task"));
		assertTrue(task.getDescription().equals("This is a test task"));
	}
	
	@Test
	void testInvalidId() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task(null, "Test Task", "This is a test task");
		});
	}
	@Test
	void testInvalidIdLength() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("12345678900000", "Test Task", "This is a test task");
		});
	}
	@Test
	void testInvalidName() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("001", null, "This is a test task");
		});
	}
	@Test
	void testInvalidNameLength() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("001", "This test task name is too long", "This is a test task");
		});
	}
	@Test
	void testInvalidDescription() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("001", "Test Task", null);
		});
	}
	@Test
	void testInvalidDescriptionLength() {
		assertThrows(IllegalArgumentException.class, () -> {
			new Task("001", "Test Task", "This test task description has too many characters too be accepted.");
		});
	}
	
}
