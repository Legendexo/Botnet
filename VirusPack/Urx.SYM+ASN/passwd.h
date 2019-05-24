char *usernames[]={
	"administrator",
	"administrador",
	"administrateur",
	"administrat",
	"admins",
	"admin",
	"staff",
	"root",
	"computer",
	"owner",
	"student",
	"teacher",
	"wwwadmin",
	"guest",
	"default",
	"database",
	"dba",
	"oracle",
	"db2",
	"webmaster",
	"TsInternetUser",
	"ASDNET",
	"host",
	"server",
	"user",
	"z",
	"zx",
	NULL
};

char *passwords[]={
	"",
	"administrator",
	"administrador",
	"administrateur",
	"administrat",
	"admins",
	"admin",
	"adm",
	"","!@#$","!@#$%","!@#$%^","!@#$%^&","!@#$%^&*","%","0","00","000","0000","00000","000000",
	"00000000","007","0wn3d","0wned","1","110","111","111111","11111111","12","121","121212",
	"123","123123","1234","12345","123456","1234567","12345678","123456789","12346","123467",
	"1234678","12346789","123467890","1234qwer","123abc","123asd","123qwe","2002","2003","2600",
	"54321","654321","88888888","Admin","Administrador","Administrateur","Administrator","Al3x",
	"Alex","Alexander","BOTH","CHECK","CHT","Changeme","Default","Dell","FILES","FULL","Gast",
	"Guest","Inviter","LOCAL","Login","M$","MP","MS","Mat","Matt","Matthew","ND","Nilez","OEM",
	"Owner","Password","RAGE","READ","ROOT","RPC","Rosco","RoscoP","RoscoPColtrane","Ross",
	"SERVER","SHARE","SYSTEM","Standard","Test","Unknown","User","WRITE","WindowsXP","a","aaa",
	"abc","abc123","abcd","academia","academic","accept","access","account","accounting",
	"accounts","action","ada","adam","adm","admin123","adrian","adrianna","adult","aerobics",
	"afro","aids","airplane","alaska","albany","albatros","albatross","albert","alert","alexande",
	"alf","algebra","alias","aliases","alice","alicia","alisa","alison","allison","allow","alpha",
	"alphabet","ama","amadeus","amanda","amber","america","amorphou","amorphous","amy","anal",
	"analog","anarchis","anarchy","anchor","andrea","android","andromac","andromache","andy",
	"anfo","angela","angerine","angie","animal","animals","anita","ann","anna","anne","annette",
	"anon","anonymou","answer","anthrax","anthropo","anthropogenic","anvils","anything","apollo13",
	"april","aria","ariadne","arlene","army","arrow","arthur","artist","asd","asdf","asdfgh",
	"asian","asm","asshole","athena","atmosphe","atmosphere","atom","attack","authoriz","aztecs",
	"azure","babe","baby","bacchus","backdoor","backup","badass","bailey","ball","banana",
	"bananas","bandit","bank","banks","barbara","barber","bare","barf","baritone","bart",
	"bartman","baseball","basic","bass","bassoon","batch","batman","beach","beammeup","bear",
	"beast","beater","beauty","beaver","becky","beethove","beethoven","begin","behead","bell",
	"beloved","benz","beowulf","berkeley","berlin","berliner","beryl","beta","beth","betsie",
	"betty","beverly","bible","bicamera","bicameral","bigfoot","bill","billy","binary","bios",
	"bird","bishop","bitch","bitmap","bitnet","bla","black","blank","blonde","blondie","blood",
	"bloodaxe","blow","blowjob","blue","blues","board","bob","bomb","boner","boob","boobs",
	"book","born","boyscout","bradley","brandi","brandy","bravo","break","breast","brenda",
	"brian","bridget","broadway","brothel","bruce","brunette","brute","brutefor","bsd","bulls",
	"bullshit","bumbling","bung","burgess","burn","butch","butt","butthead","cad","californ",
	"camille","campanil","campanile","camping","candi","candy","cantor","capitol","captain",
	"capture","card","cardinal","caren","carla","carmen","carol","carole","carolina","caroline",
	"carrie","carson","cascades","cash","castle","cat","catherin","catherine","catholic",
	"cathy","cave","cayuga","cecily","celt","celtic","celtics","cerulean","change","charity",
	"charles","charlie","charming","charon","chat","chem","chemistr","chemistry","chess","chester",
	"chip","chris","christin","christina","christine","christy","cigar","cigarett","cindy",
	"cisco","class","classes","classic","claudia","claymore","cleavage","clinton","cluster",
	"clusters","coast","cocacola","cocainco","cock","code","codename","codeword","coffee","coin",
	"coke","cola","cold","collins","color","combat","comics","commit","commrade","commrades",
	"company","compaq","computer","computin","comrade","comrades","condo","condom","connect",
	"connie","conserva","console","continue","control","cook","cookbook","cookie","cool","cooper",
	"copper","cops","copy","corneliu","cornelius","correct","counters","country","couscous",
	"cowboy","crack","crackpot","crash","cream","create","creation","creature","credit","creosote",
	"cretin","crime","criminal","cristina","crystal","cshrc","ctx","cunt","customer","cyber",
	"cyberpun","cyberspa","cynthia","d00d","daemon","daisy","dana","dancer","daniel","danielle",
	"danny","dapper","dark","darkaven","data","database","databasepass","databasepassword","dave",
	"dawn","db1","db1234","dbpass","dbpassword","dead","death","deathsta","deb","debbie","deborah",
	"debug","december","deck","defoe","delta","deluge","demo","democrat","denise","dennis",
	"desiree","desk","desktop","desperat","desperate","develop","device","devil","dial","diamond",
	"diana","diane","dice","dick","diehard","diet","dieter","digital","dinosaur","dipshit",
	"direct","director","dirty","disc","discipli","disclose","discover","discovery","disk",
	"diskette","disney","display","doctor","dog","dollar","domain","domainpass","domainpassword",
	"donaldduck","dong","doom","doom2","doomii","doomsday","doonesbu","door","doors","dope","dos",
	"download","dragon","drdoom","drive","drought","duck","dud3","dude","dudette","duelist","duke",
	"dulce","duncan","dungeon","dyke","eager","eagle","earth","easier","easy","eatme","echo",
	"eddie","edges","edinburg","edinburgh","edit","edition","edu","educatio","education","edwin",
	"edwina","egghead","eiderdow","eiderdown","eileen","einsiein","einstein","elaine","elanor",
	"electron","elephant","elizabet","elizabeth","ellen","email","emerald","emily","emmanuel",
	"enable","enemy","engine","engineer","england","english","enter","enterpri","enterprise",
	"enzyme","erenity","eric","erica","erika","erin","erotic","ersatz","establis","establish",
	"estate","eternity","euclid","evelyn","exchange","exchnge","expert","explode","explore",
	"explorer","explosiv","extensio","extension","fairway","faith","falcon","false","family",
	"farad","faraday","fart","fast","fear","feds","felicia","fender","fermat","ferrari","fidelity",
	"field","fight","file","finite","fire","firewall","fish","fishers","flakes","float","florida",
	"flower","flowers","foobar","food","fool","foolproo","foolproof","football","force","ford",
	"foresigh","foresight","forever","form","format","fornicat","forsythe","fourier","foxtrot",
	"france","frank","freak","fred","freddy","free","freedom","french","friday","friend","friends",
	"frighten","frog","fryguy","fubar","fuck","fucked","fucker","fucking","fuckme","fuckyou",
	"fudge","fun","function","fungible","gabriel","games","gardner","garfield","gateway",
	"gatherin","gatt","gauss","george","germ","gertrude","ghost","gibson","gigabyte","gina",
	"ginger","girl","glacier","glen","gnu","gobo","god","godblessyou","gold","golden","golf",
	"golfer","good","gorgeous","gorges","gosling","gouge","govermen","grades","graham","grahm",
	"grand","grant","great","green","group","gryphon","guardian","gucci","guess","guessme",
	"guitar","gumption","guntis","h4x0r1ng","h4x0ring","h4x1ng","hack","hacked","hacker","hagar",
	"hair","hal","hallowee","hamlet","hamster","handel","handily","handjob","happenin","happening",
	"hard","hardcore","harddriv","harmony","harold","harvey","hate","haven","hawaii","hax","hax0r",
	"haxing","head","headbang","headoffice","heat","heathen","heather","heaven","hebrides","heidi",
	"heinlein","hell","hello","help","herb","herbert","hero","heroin","hewlett","hexadeci",
	"hiawatha","hibernia","hidden","high","highland","hitler","hits","ho","hole","holly",
	"hollywoo","home","homepage","homer","homeuser","homework","honey","hooker","hooters","horny",
	"horrible","horror","horse","horus","host","hotdog","hotel","hq","http","hunt","hunter",
	"hutchins","hydrogen","hyper","hypertxt","ian","ibm","icecream","ihavenopass","illumina",
	"image","imbrogli","imbroglio","immortal","imperial","include","india","indian","indiana",
	"indians","ingres","ingress","ingrid","inna","innocuou","innocuous","input","inside","integer",
	"internet","intranet","invent","irene","irishman","irule","isis","jackie","jail","jane",
	"janet","janice","janie","japan","jasmin","java","jazz","jean","jeanne","jeff","jen","jenni",
	"jennifer","jenny","jerry","jerusale","jessica","jester","jewelry","jill","jixian","joan",
	"joanne","jody","joe","john","johndoe","johnny","joseph","joshua","journal","joy","joyce",
	"judith","judy","juggle","juicy","julia","julie","juliet","june","jupiter","kaka","karen",
	"karie","karina","katana","kate","kathleen","kathrine","kathy","katie","katina","katrina",
	"kelly","keri","kermit","kernel","kerri","kerrie","kerry","kevin","kewl","key","keybord",
	"keyin","keyword","kiddie","kids","kill","killer","killthem","kilo","kim","kimberly","king",
	"kirk","kirkland","kiss","kissmyas","kitten","klingon","knife","knight","knightma","known",
	"krista","kristen","kristi","kristie","kristin","kristine","kristy","l337","l33t","ladies",
	"ladle","lakers","lambda","laminati","lamination","lan","lana","laptop","lara","larkin",
	"larry","laser","laura","lava","lazarus","lazer","leah","lebesgue","lee","leet","left",
	"leftwing","legal","leland","leroy","lesbian","leslie","letmein","lewis","lexluthe","liberal",
	"library","lick","licker","life","light","lightsab","lima","limbaugh","limited","linda",
	"link","linux","lion","lips","lisa","lisp","literatu","live","liz","load","lock","lockout",
	"lockword","logic","loginpass","loginwor","logout","lois","lol","lolopc","loose","lore",
	"lori","lorin","lorraine","loser","louis","love","lovebug","lover","luck","lucus","lucy",
	"lude","luke","lust","lynn","lynne","machine","macintos","macintosh","mack","macro","maggot",
	"magic","magnet","mail","main","maint","malcolm","malcom","mana","manager","mara","marci",
	"marcy","maria","mariens","marietta","marijuan","marines","mark","markus","marni","marriage",
	"mars","marty","marvin","mary","mason","mass","master","math","maurice","meagan","megabyte",
	"megadeth","megan","melissa","mellon","melrose","member","memory","menace","menu","mercury",
	"megadeth","megan","melissa","mellon","melrose","member","memory","menace","menu","mercury",
	"merlin","metal","metalhea","metalica","mets","mgr","mice","michael","michel","michelan",
	"michele","michelle","mickey","micro","microchi","micropro","microsof","midieval","mike",
	"mine","minimum","minsky","mirc","misfit","mission","mit","mkii","mode","modem","mogul",
	"moguls","monday","monica","moom","moor","moose","more","morley","morris","mortal","mortalco",
	"mortgage","mosaic","mountain","mouse","move","movie","movies","mozart","mpeg","msdos",
	"muppets","mutant","mypass","mypass123","mypc","mypc123","nagel","name","nancy","napoleon",
	"nasa","navy","neil","nepenthe","neptune","ness","net","net-devil","netbios","netdevil",
	"netfuck","netscape","network","new","newborn","news","newsgrou","newton","newyork","next",
	"nice","nicole","nicotine","night","nightmar","nintendo","nita","nnaacp","noble","nobody",
	"node","nokia","none","noob","noreen","notes","noth","nova","novel","november","noxious",
	"nuclear","nude","nuke","nukem","null","number","nutritio","nutrition","nuts","nyquist",
	"obscurit","oceanogr","oceanography","ocelot","oeminstall","oemuser","office","okay","oldage",
	"olivetti","olivia","omega","open","opening","openlock","opensesa","operator","oracle",
	"orange","orca","orient","orwell","oscar","osiris","outdoors","outlaw","outlook","output",
	"outside","owa","own","owned","oxford","pacific","packard","packer","pad","painless","paint",
	"pakistan","pam","pamela","papa","paper","papers","pascal","pass","pass123","pass1234",
	"passphra","passwd","password1","password123","paste","pat","patricia","patrick","patriot",
	"patty","paula","pc","peanuts","pecker","pencil","penelope","penguin","penis","penname",
	"pentagon","pentagra","penthous","pentium","peoria","pepper","pepsi","percolat","percolate",
	"perfect","permit","persimmo","persimmon","persona","pervert","pete","peter","phil","philip",
	"phoenix","phone","photon","phrack","phrase","phreak","phuck","pick","pierre","pimp","pink",
	"pinname","piss","pizza","plane","playboy","plover","pluto","plymouth","poetry","police",
	"polly","polynomi","polynomial","ponderin","pondering","poop","poor","pork","porn","porno",
	"porsche","post","poster","power","praise","precious","prelude","presto","prince","princeto",
	"princeton","printer","priv","private","privs","proceed","processo","professo","professor",
	"profile","program","prompt","protect","protozoa","psycho","psychopa","pub","public","puck",
	"puke","pumpkin","puneet","punisher","punk","puppet","pussy","pw","pw123","pwd","qaz","quebec",
	"qwe","qwer","qwert","qwerty","r00t","rabbit","rachel","rachelle","rachmani","rachmaninoff",
	"raid","rain","rainbow","raindrop","raleigh","random","rape","rascal","razor","reagan",
	"reality","really","ream","reaper","rebal","rebecca","rebel","record","reddawn","redhead",
	"referenc","regional","release","remote","renee","reno","rent","report","republic","resistan",
	"reveal","rhino","rich","rick","riffraff","right","rightwin","ring","riot","ripple","risc",
	"rje","roach","robert","robin","robot","robotics","robyn","rochelle","rocheste","rochester",
	"rock","rocky","rockyhor","rodent","rolex","romano","romeo","romulan","ron","ronald","rooted",
	"rose","rosebud","rosemary","roses","rough","rubber","ruben","ruby","rude","rules","running",
	"rush","ruth","sa","safe","sage","sal","salami","sale","salt","sam","samantha","sample",
	"sandra","sandy","sara","sarah","satan","satanic","satanik","saturday","saturn","saxon",
	"scamper","scheme","school","schoolsucks","scifi","scorpion","scott","scotty","scout","script",
	"scriptkiddie","search","secret","security","seed","sega","sensor","sentinel","sentry",
	"serenity","serial","service","sesame","sex","sexy","shannon","sharc","shark","sharks","sharon",
	"sheffiel","sheffield","sheldon","shell","sherri","shift","shirley","shit","shitpot","shiva",
	"shivers","short","shuttle","sick","siemens","sierra","signatur","signature","silver","simcity",
	"simon","simple","simpsons","simulati","singer","single","site","skull","slave","slick","sliders",
	"slow","slut","small","smart","smile","smiles","smooch","smother","smtp","smut","snach","snafu",
	"snake","snatch","snoopy","soap","social","socrates","sodomy","soft","software","somebody",
	"sondra","sonia","sonic","sonya","sossina","source","south","spaceman","spaceshi","sparrows",
	"spear","spell","spencer","spice","spider","spiderma","spit","spred","spring","springer","spunk",
	"sql","sqlagent","sqlpass","squires","sr71","stacey","staci","stacie","stacy","staff","star",
	"starship","start","startrek","startup","starwars","steak","steal","steel","steph","stephani",
	"stephanie","stereo","steve","stoneage","stoned","stones","strange","strangle","stratfor",
	"stratford","streetfi","string","strip","student","student1","stuttgar","stuttgart","subscrib",
	"subway","success","suck","suckmydi","sucks","sue","summer","sun","sunday","super","superman",
	"superson","supersta","superstage","superuse","superuser","supervis","support","supporte",
	"supported","surfer","surfing","susan","susanne","susie","suzanne","suzie","swearer","sweat",
	"switch","sword","sybase","sybil","symmetry","sys","sysadmin","sysop","tabasco","talk","tall",
	"tamara","tami","tamie","tammy","tangerin","tangerine","tango","tape","tara","target","tarragon",
	"taylor","teacher","team","teapot","tears","tech","technical","teen","teenage","telephon",
	"telephone","telnet","temp","temp123","temptati","temptation","tennis","tera","terminal",
	"terminat","tess","test123","tester","testin","testing","tetris","text","thailand","theresa",
	"thin","thursday","tiffany","tiger","time","tina","tits","toad","toggle","token","tokenrin",
	"tomato","topograp","topography","tortoise","toxic","toyota","traci","tracie","tracy","trails",
	"transfer","trap","trapdoor","tree","trek","trisha","trivial","trojan","trombone","tron","true",
	"truth","tty","tubas","tuesday","turn","turnip","tuttle","ugly","umesh","uncle","undo","unhappy",
	"unicorn","uniform","universa","universe","universi","unix","unlock","upload","uranus","urchin",
	"ursula","usenet","user1","usermane","username","userpassword","usmc","util","utility","uucp",
	"uwontguessme","vagina","valerie","vampire","vasant","venus","veronica","vertigo","vicky",
	"victor","video","videogam","village","virgin","virginia","virus","visitor","visual","visualba",
	"vodka","w00t","waco","ward","warez","warfare","wargames","warp","warren","wasp","watchwor",
	"water","wave","web","webpage","wednesda","weed","weenie","well","wendi","wendy","werewolf",
	"west","western","wh0r3","wh0re","whatever","whatnot","whisky","white","whiting","whitney",
	"wholesal","wholesale","whore","wileecoyote","will","william","williams","williamsburg","willie",
	"wilma","win","win2000","win2k","win98","windose","windows","windows2k","windows95","windows98",
	"windowsME","windowz","windoze","windoze2k","windoze95","windoze98","windozeME","windozexp",
	"wine","wing","winnt","winpass","winston","winxp","wired","wisconsi","wisconsin","wiseass",
	"within","wizard","wolf","wolverin","woman","wombat","women","wood","woodwind","word","wordperf",
	"worf","work","worm","wormwood","wwii","www","wwwadmin","wyoming","x","xena","xfer","xman","xmen",
	"xmodem","xp","xray","xx","xxx","xxxx","xxxxx","xxxxxx","xxxxxxx","xxxxxxxx","xxxxxxxxx","xyz",
	"xyzzy","yaco","yang","yankee","yellow","yellowst","yellowstone","yolanda","yosemite","young",
	"youwontguessme","yxcv","zap","zebra","zeitgeis","ziggy","zimmerma","zimmerman","zmodem","zombie",
	"zulu","zxc","zxcv",
	"1952",
	"1953",
	"1954",
	"1955",
	"1956",
	"1957",
	"1958",
	"1959",
	"1960",
	"1961",
	"1962",
	"1963",
	"1964",
	"1965",
	"1966",
	"1967",
	"1968",
	"1969",
	"1970",
	"1971",
	"1972",
	"1973",
	"1974",
	"1975",
	"1976",
	"1977",
	"1978",
	"1979",
	"1980",
	"1981",
	"1982",
	"1983",
	"1984",
	"1985",
	"1986",
	"1987",
	"1988",
	"1989",
	"1990",
	"1991",
	"1992",
	"1993",
	"1994",
	"1995",
	"1996",
	"1997",
	"1998",
	"1999",
	"2000",
	"2001",
	"2002",
	"2003",
	"2004",
	"2005",
	"2006",
	"2007",
	"2600",
	"321",
	"4321",
	"54321",
	"654321",
	"7654321",
	"sony",
	"xp2005",
	"xp2006",
	"2006xp",
	"2005xp",
	"SAMSUNG",
	"samsung",
	"SONY",
	"MASTER",
	"MICROSOFT",
	"DISC",
	"CREATIVE",
	"SEX",
	"NOKIA",
	NULL
};
