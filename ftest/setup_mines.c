void setup_mines();
{
	t_demineur demineur
	int tmpCellx;
	int tmpCelly;

	for (int i = 0; i < demineur.nBomb; ++i)
	{
		tmpCellx = rand()%demineur.Map_Size.x + 1;
		tmpCelly = rand()%demineur.Map_Size.y + 1;

		while(demineur.map[tmpCellx][tmpCelly].isBomb == true)
		{
			tmpCellx = rand()%demineur.Map_Size.x + 1;
			tmpCelly = rand()%demineur.Map_Size.y + 1;
		}

		demineur.map[tmpCellx][tmpCelly].isBomb = true;
	}

}