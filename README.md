# snake-fugas
# ������� #:
**Cell** - ������� ����
��� �������� ������ ����������
����������:
	free<bool> - ����� ��� �������
	customTexture
	changeDir<bool>
	direction<char>?

������:
	ChangeDir(newDir):
		if(newDir == ' ')
			changeDir = false;
		direction = newDir;	

**Field** - ����
��� �������� ����, ���������� ���� (����� �������)
����������:	
	rows<int>
	cols<int>
	cells<Cell[rows][cols]> - �������� ����� ������

������:
	GetCell(int row, int col):
		return cells[row][col];	

**Bodypart**
����������:
	cell<Cell>
	dir<char>

������:
	ChangeDir(newDir):
		dir = newDir;	
	
**Food**
����������:
	customTexture
	score<int>? - ��������� ������� ��
	tag<string>

������:
	Destroy:
		GameManager.UpdateScore(score);
		������� ��������� score
		����� �� ���

**Snake**
��� �������� ��������� ��������
����������:
	direction<char>
	body<bodypart>
	tag<string>

������:
	canMoveTo(int row, int col):
		
	Move:
		
		���������� ������ �������� �� ��������
		
	ChangeDir(newDir):
		���� ����
		

**GameManager**
������� ���� � ������.
����������:
	player<Snake>
	field<Field>
	score<int>?
	
������:
	static UpdateScore(+score)
		this->score += score;
	
	ChangeMoveDir(newDir):
		//
		for(part : player.body):
			part_cell = part.getCell()
			newCell = field.getNextCellByDir(part_cell, newDir);
			part.setCell(newCell)
		//
		cell = field.getCell(player.head)
		cell.changeDir(newDir)
		player.changeDir(newDir)
		
	PerformGameSession:
		����������� �������
		�������� ����
		����������� �������
		�������� ������
		�������� ��������� food
	