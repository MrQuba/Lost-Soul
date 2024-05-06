#pragma once
enum class EXIT_CODE : int {
	OPERATION_SUCCESFUL,
	TERMINATED,
	RETURNED_NULL,
	SET_IS_EMPTY,
	OBJECT_DESTRUCTED,
	FILE_NOT_DECLARED,
	FILE_OPENED_SUCCESFULLY,
	WINDOW_IS_NOT_OPEN,
	CLOSED_WINDOW_SUCCESSFULLY,
	SPRITE_COLLIDED,
	RETURN_VOID,
	NOT_AFFECTED_BY_GRAVITY
};