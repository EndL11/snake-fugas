# snake-fugas
# Сутності #:
**Cell** - одиниця поля
При створенні приймає координати
Властивості:
	free<bool> - вільна або зайнята
	customTexture
	changeDir<bool>
	direction<char>?

Методи:
	ChangeDir(newDir):
		if(newDir == ' ')
			changeDir = false;
		direction = newDir;	

**Field** - поле
При створенні поля, отримувати крок (розмір спрайта)
Властивості:	
	rows<int>
	cols<int>
	cells<Cell[rows][cols]> - двомірний масив комірок

Методи:
	GetCell(int row, int col):
		return cells[row][col];	

**Bodypart**
Властивості:
	cell<Cell>
	dir<char>

Методи:
	ChangeDir(newDir):
		dir = newDir;	
	
**Food**
Властивості:
	customTexture
	score<int>? - збільшення рахунку на
	tag<string>

Методи:
	Destroy:
		GameManager.UpdateScore(score);
		викликає додавання score
		знищує об єкт

**Snake**
При створенні завантажує текстури
Властивості:
	direction<char>
	body<bodypart>
	tag<string>

Методи:
	canMoveTo(int row, int col):
		
	Move:
		
		переміщення гравця відповідно до напрямку
		
	ChangeDir(newDir):
		Зміна руху
		

**GameManager**
Створює поле і гравця.
Властивості:
	player<Snake>
	field<Field>
	score<int>?
	
Методи:
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
		завантажити спрайти
		створити поле
		згенерувати границі
		створити гравця
		рандомно розмістити food
	