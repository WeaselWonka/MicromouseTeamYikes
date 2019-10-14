
short shiftClockwise(short direction)
{
	return (direction + 1) % 4;
}

short shiftCounterClockwise(short direction)
{
	if (direction == 0)
		return 3;
	return (direction - 1) % 4;
}