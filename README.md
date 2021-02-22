# snake-fugas
Сутності #:
Cell - одиниця поля 
При створенні приймає координати 
Властивості: 
    free - вільна або зайнята 
    customTexture 
    changeDir 
    direction?

Методи: 
    ChangeDir(newDir): 
        if(newDir == ' ') 
            changeDir = false; 
        direction = newDir;


Field - поле 
При створенні поля, отримувати крок (розмір спрайта) 
Властивості: 
    rows 
    cols 
    cells<Cell[rows][cols]> - двомірний масив комірок

Методи: 
    GetCell(int row, int col): 
        return cells[row][col];

Bodypart 
Властивості: 
    cell 
    dir

Методи: 
    ChangeDir(newDir): 
        dir = newDir;

Food 
Властивості: 
    customTexture 
    score? - збільшення рахунку на 
    tag

Методи: 
    Destroy: 
        GameManager.UpdateScore(score); 
        викликає додавання score 
        знищує об єкт

Snake 
При створенні завантажує текстури 
Властивості: 
    direction 
    body 
    tag

Методи: 
    canMoveTo(int row, int col):

    Move:   
        переміщення гравця відповідно до напрямку

    ChangeDir(newDir):
        Зміна руху

GameManager 
Створює поле і гравця. 
Властивості: 
    player 
    field 
    score?

Методи: 
    UpdateScore(+score) 
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