//
//  test_long_line.c
//  get_next_line
//
//  Created by Yuliia Demura on 12/5/20.
//  Copyright © 2020 Yuliia Demura. All rights reserved.
//

#include "test_get_next_line.h"
#include "get_next_line.h"

#define FIXTURES_PATH_HOME "/Users/julia/Desktop/GNL/get_next_line/get_next_line/tests/test_long_line/"
#define FIXTURES_PATH_CODAM "/Users/ydemura/Desktop/get_next_line/get_next_line/get_next_line/tests/test_long_line/"

void	test_longline(void)
{
	int fd;
	char *line;

	fd = open(FIXTURES_PATH"long_line.txt", O_RDONLY);
	if (fd == -1)
		printf("not opened\n\n");
	assert(fd != -1);
//	else
//		printf(".......................opened\n");
	
	line = NULL;
	
	int res;
	res = 1;
	int i = 1;
	res = get_next_line(fd, &line);
	assert(strcmp(line, "DRACULACHAPTER IJONATHAN HARKER'S JOURNAL(_Kept in shorthand._)_3 May. Bistritz._--Left Munich at 8:35 P. M., on 1st May, arriving atVienna early next morning; should have arrived at 6:46, but train was anhour late. Buda-Pesth seems a wonderful place, from the glimpse which Igot of it from the train and the little I could walk through thestreets. I feared to go very far from the station, as we had arrivedlate and would start as near the correct time as possible. Theimpression I had was that we were leaving the West and entering theEast; the most western of splendid bridges over the Danube, which ishere of noble width and depth, took us among the traditions of Turkishrule.We left in pretty good time, and came after nightfall to Klausenburgh.Here I stopped for the night at the Hotel Royale. I had for dinner, orrather supper, a chicken done up some way with red pepper, which wasvery good but thirsty. (_Mem._, get recipe for Mina.) I asked thewaiter, and he said it was called paprika hendl, and that, as it was anational dish, I should be able to get it anywhere along theCarpathians. I found my smattering of German very useful here; indeed, Idon't know how I should be able to get on without it.Having had some time at my disposal when in London, I had visited theBritish Museum, and made search among the books and maps in the libraryregarding Transylvania; it had struck me that some foreknowledge of thecountry could hardly fail to have some importance in dealing with anobleman of that country. I find that the district he named is in theextreme east of the country, just on the borders of three states,Transylvania, Moldavia and Bukovina, in the midst of the Carpathianmountains; one of the wildest and least known portions of Europe. I wasnot able to light on any map or work giving the exact locality of theCastle Dracula, as there are no maps of this country as yet to comparewith our own Ordnance Survey maps; but I found that Bistritz, the posttown named by Count Dracula, is a fairly well-known place. I shall enterhere some of my notes, as they may refresh my memory when I talk over mytravels with Mina.In the population of Transylvania there are four distinct nationalities:Saxons in the South, and mixed with them the Wallachs, who are thedescendants of the Dacians; Magyars in the West, and Szekelys in theEast and North. I am going among the latter, who claim to be descendedfrom Attila and the Huns. This may be so, for when the Magyars conqueredthe country in the eleventh century they found the Huns settled in ita. Iread that every known superstition in the world is gathered into thehorseshoe of the Carpathians, as if it were the centre of some sort ofimaginative whirlpool; if so my stay may be very interesting. (_Mem._, Imust ask the Count all about them.)I did not sleep well, though my bed was comfortable enough, for I hadall sorts of queer dreams. There was a dog howling all night under mywindow, which may have had something to do with it; or it may have beenthe paprika, for I had to drink up all the water in my carafe, and wasstill thirsty. Towards morning I slept and was wakened by the continuousknocking at my door, so I guess I must have been sleeping soundly then.I had for breakfast more paprika, and a sort of porridge of maize flourwhich they said was mamaliga, and egg-plant stuffed with forcemeat, avery excellent dish, which they call impletata. (_Mem._, get recipefor this also.) I had to hurry breakfast, for the train started a littlebefore eight, or rather it ought to have done so, for after rushing tothe station at 7:30 I had to sit in the carriage for more than an hourbefore we began to move. It seems to me that the further east you go themore unpunctual are the trains. What ought they to be in China?All day long we seemed to dawdle through a country which was full ofbeauty of every kind. Sometimes we saw little towns or castles on thetop of steep hills such as we see in old missals; sometimes we ran byrivers and streams which seemed from the wide stony margin on each sideof them to be subject to great floods. It takes a lot of water, andrunning strong, to sweep the outside edge of a river clear. At everystation there were groups of people, sometimes crowds, and in all sortsof attire. Some of them were just like the peasants at home or those Isaw coming through France and Germany, with short jackets and round hatsand home-made trousers; but others were very picturesque. The womenlooked pretty, except when you got near them, but they were very clumsyabout the waist. They had all full white sleeves of some kind or other,and most of them had big belts with a lot of strips of somethingfluttering from them like the dresses in a ballet, but of course therewere petticoats under them. The strangest figures we saw were theSlovaks, who were more barbarian than the rest, with their big cow-boyhats, great baggy dirty-white trousers, white linen shirts, and enormousheavy leather belts, nearly a foot wide, all studded over with brassnails. They wore high boots, with their trousers tucked into them, andhad long black hair and heavy black moustaches. They are verypicturesque, but do not look prepossessing. On the stage they would beset down at once as some old Oriental band of brigands. They are,however, I am told, very harmless and rather wanting in naturalself-assertion.It was on the dark side of twilight when we got to Bistritz, which is avery interesting old place. Being practically on the frontier--for theBorgo Pass leads from it into Bukovina--it has had a very stormyexistence, and it certainly shows marks of it. Fifty years ago a seriesof great fires took place, which made terrible havoc on five separateoccasions. At the very beginning of the seventeenth century it underwenta siege of three weeks and lost 13,000 people, the casualties of warproper being assisted by famine and disease.Count Dracula had directed me to go to the Golden Krone Hotel, which Ifound, to my great delight, to be thoroughly old-fashioned, for ofcourse I wanted to see all I could of the ways of the country. I wasevidently expected, for when I got near the door I faced acheery-looking elderly woman in the usual peasan dress--whiteundergarment with long double apron, front, and back, of coloured stufffitting almost too tight for modesty. When I came close she bowed andsaid, The Herr Englishman? Yes, I said, Jonathan Harker. Shesmiled, and gave some message to an elderly man in white shirt-sleeves,who had followed her to the door. He went, but immediately returned witha letter:--     My Friend.--Welcome to the Carpathians. I am anxiously expecting     you. Sleep well to-night. At three to-morrow the diligence will     start for Bukovina; a place on it is kept for you. At the Borgo     Pass my carriage will await you and will bring you to me. I trust     that your journey from London has been a happy one, and that you     will enjoy your stay in my beautiful land.Your friend,DRACULA._4 May._--I found that my landlord had got a letter from the Count,directing him to secure the best place on the coach for me; but onmaking inquiries as to details he seemed somewhat reticent, andpretended that he could not understand my German. This could not betrue, because up to then he had understood it perfectly; at least, heanswered my questions exactly as if he did. He and his wife, the oldlady who had received me, looked at each other in a frightened sort ofway. He mumbled out that the money had been sent in a letter, and thatwas all he knew. When I asked him if he knew Count Dracula, and couldtell me anything of his castle, both he and his wife crossed themselves,and, saying that they knew nothing at all, simply refused to speakfurther. It was so near the time of starting that I had no time to askany one else, for it was all very mysterious and not by any meanscomforting.Just before I was leaving, the old lady came up to my room and said in avery hysterical way: She was in such an excitedstate that she seemed to have lost her grip of what German she knew, andmixed it all up with some other language which I did not know at all. Iwas just able to follow her by asking many questions. When I told herthat I must go at once, and that I was engaged on important business,she asked again: I answered that it was the fourth of May.She shook her head as she said again:. Do you not know that to-night, whenthe clock strikes midnight, all the evil things in the world will havefull sway? Do you know where you are going, and what you are going to?She was in such evident distress that I tried to comfort her, butwithout effect. Finally she went down on her knees and implored me notto go; at least to wait a day or two before starting. It was all veryridiculous but I did not feel comfortable. However, there was businessto be done, and I could allow nothing to interfere with it. I thereforetried to raise her up, and said, as gravely as I could, that I thankedher, but my duty was imperative, and that I must go. She then rose anddried her eyes, and taking a crucifix from her neck offered it to me. Idid not know what to do, for, as an English Churchman, I have beentaught to regard such things as in some measure idolatrous, and yet itseemed so ungracious to refuse an old lady meaning so well and in such astate of mind. She saw, I suppose, the doubt in my face, for she put therosary round my neck, and said, For your mother's sake, and went outof the room. I am writing up this part of the diary whilst I am waitingfor the coach, which is, of course, late; and the crucifix is stillround my neck. Whether it is the old lady's fear, or the many ghostlytraditions of this place, or the crucifix itself, I do not know, but Iam not feeling nearly as easy in my mind as usual. If this book shouldever reach Mina before I do, let it bring my good-bye. Here comes thecoach!       *       *       *       *       *") == 0);
	assert(res == 1);
//	printf("%i | line %i: %s\n",res, i, line);
	free(line);
	i++;
	
	res = get_next_line(fd, &line);
	assert(strcmp(line, "") == 0);
	assert(res == 0);
	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "bb") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "ccc") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "dddd") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "eeeee") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "ffffff") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "a") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "a") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "bb") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "ccc") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "a") == 0);
//	assert(res == 1);
//	free(line);
//
//	res = get_next_line(fd, &line);
//	assert(strcmp(line, "") == 0);
//	assert(res == 0);
//	free(line);
	

	if (close(fd) < 0)
		printf("not closed\n");
//	else
//		printf(".......................closed\n");
}
