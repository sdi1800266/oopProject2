!!!!ΠΟΛΥ ΣΗΜΑΝΤΙΚΟ!!!!
Για να διαβάζει και να επεξεργάζεται το πρόγραμμα το αρχείο secretaryinput τότε 
θα πρέπει να το έχουμε στο ίδιο folder με το υπόλοιπο πρόγραμμα.


***semestertype.h***
	Περιλαμβάνει τις βιβλιοθήκες που χρησιμοποιούμε(iostream,vector,string,cstring,map,fstream) και κάνει συστήνει την έννοια των ακαδημαϊκών εξαμήνων(FALL1 = 1, FALL2 = 3, FALL3 = 5, FALL4 = 7,SPRING1 = 2, SPRING2 = 4, SPRING3 = 6, SPRING4 = 8).

***person.h***
	Η κλάση person που περιέχει name,age,email,gender,nationality,id καθώς και
ένα semester το οποίο χρησιμοποιείται για τους students και
ένα static int count για το πλήθος των αντικειμένων person που έχουν δημιουργηθεί.

***person.cpp***
	Η υλοποιήσεις για τις πληροφορίες του αντικειμένου person και η συνάρτηση printPersonDetails() που εμφανίζει αυτές τις πληροφορίες.

***professor.h***
	Απλά κληρονομεί την person για να δημιουργεί αντικείμενα professor.

***professor.cpp***
	default class constructor for professor

***student.h***
	Απλά κληρονομεί την person για να δημιουργεί αντικείμενα student προσθέτοντας και την μεταβλητή semester που δηλώνει σε ποιο εξάμηνο βρίσκεται ο κάθε μαθητής.
Αξίζει να σημειωθεί ότι εάν κάποιος μαθητής είναι άνω του 8ου εξαμήνου θεωρείται ό,τι μπορεί να παρακολουθήσει τα μαθήματα όλων των προηγούμενων εξαμήνων μαζί με το δικό του.

Περιέχει επίσης δύο map: enrolledCourses και passedCourses στα οποίο με key το object student έχουμε πρόσβαση στα μαθήματα που έχει κάνει εγγραφή ένας μαθητής(μπορεί να κάνει εγγραφή μόνο σε μαθήματα παλαιότερων εξαμήων,εκτός και αν είναι επι πτυχίω όπου μπορεί να εγγραφεί σε όλα τα μαθήματαανεξάρτητα από το εξάμηνο).

***student.cpp**
	default constructor for student

***course.h***
	Η κλάση course που περιέχει το coursename,semeser,ects,mandatory για το course.
καθώς και μια μεταβλητή idProfessor ώστε ένας καθηγητής με βάση το iD του να μπορεί να ανατεθεί σε ένα μάθημα.

***course.cpp***
	Πέρα απ τις απαραίτητες πληροφορίες για το course γίνεται χρήση των συναρτήσεων moveCourseToSemester που μετακινεί ένα course σε ένα άλλο εξάμηνο και της printCourseDetails που εκτυπώνει τα δεδομένα ενός course.

***secretary.h***
	περιέχει vector person(εργασία 1) και vectors για να αποθηκεύονται αντικείμενα professor,student,course με όνομα professors,students,courses αντίστοιχα.
Περιέχει τις συναρτήσεις για τα ζητούμενα της εργασίας.

***secretary.cpp***

1)addPerson: adds a person object to the vector named "persons" containing Person objects.
2)editPerson: edit an existing by traversing the "persons" vector,using their personId(which 	is an int) in order to find them.
3)deletePerson:deletes an existing person by traversing the "persons" vector,using their 	personID to find them.
4)addProfessor
5)editProfessor
6)deleteProfessor
7)addStudent
8)editStudent
9)deleteStudent
10)addCourse
11)editCourse
12)deleteCourse

13)assignProfessorToCourse:
	using the professor and course object informations uses the professor's id
	and assigns it to the course.One professor is assigned to each course.

14)enrollStudentToCourse:
	έχοντας ως πληροφορίες ένα object student και ένα object course,χρησιμοποιούμε το 	map enrolled courses και με key το όνομα του student αρχικά ελέγχουμε ό,το ο 	φοιτητής μπορεί να κάνει enroll στο course λόγω του εξαμήνου του και έπειτα 	εισάγουμε στο map το όνομα του μαθήματος και αρχικοποιούμε τη βαθμολογία με -1. 
	π.χ.Diamantopoulos_Thodoris[Object_Oriented_Programming,-1]

15)gradeStudents:
	χρησιμοποιούμε τις πληροφορίες student,course,professor,grade(grade is type float).
	τσεκάρουμε ότι το ID του professor αντιστοιχεί στο συγκεκριμένο course και εφόσον 	αντιστοιχεί o καθηγητής βάζει στο map enrolledCourses έναν βαθμό.

	ελέγχουμε επίσης αν ο βαθμός είναι προβιβάσιμος(>=5) και αν είναι χρησιμοποιούμε το 	map passedCourses ώστε να το χρησιμοποιήσουμε έπειτα στις συναρτήσεις που χρειάζεται 	ο student για να εκτυπώσει τα χαρακτηριστικά του και για να ελέγξουμε αν μπορεί να 	πάρει πτυχίο.

	επίσης εάν ο βαθμός είναι προβιβάσιμος αυξάνουμε το σύνολο των ects που έχει ο 	φοιτητής και αν το μάθημα είναι υποχρεωτικό αυξάνουμε +1 την τιμή mandatoryCourses  	με στόχο για πτυχίο τα 18 υποχρεωτικά μαθήματα. 

16)passedCourse:
	παίρνοντας σαν πληροφορία το course κάνουμε traverse το map enrolledCourses.
χρησιμοποιούμε την βιβλιοθήκη fstream για να δημιουργήσουμε ένα αρχείο με τους φοιτητές που πέρασαν ένα συγκεκριμένο μάθημα σε ένα συγκεκριμένο εξάμηνο. 
	 

17)professorStatistics:
	χρησιμοποιώντας ένα αντικείμενο professor και έχοντας αρχικοποιήσει δύο μεταβλητές 	sumPassed και sumFailed ελέγχουμε κατ αρχάς αν ο professor διδάσκει το course 	χρησιμοποιώντας το id του(ένας professor μπορεί να διδάσκει περισσότερα από ένα 	courses) και έπειτα κάνουμε traverse το map enrolledCourses(υποθέτουμε ό,τι αν 	κάποιος μαθητής έχει δηλώσει ένα μάθημα τότε θα πάει να το δώσει :P ).
	Για κάθε μαθητή που περνάει το μάθημα αυξάνεται ο μετρητής sumPassed και για κάθε 	μαθητή που κόβεται αυξάνεται ο μετρητής sumFailed.
	Τέλος εκτυπώνεται το sumPassed,sumFailed και το ποσοστό επιτυχίας
	
	sumPassed/(sumFailed+sumPassed) *100

18)studentStatisticsSemester:
	χρησιμοποιούμε ένα αντικείμενο student και αρχικά παίρνουμε την πληροφορία semester 	ώστε να γνωρίζουμε σε ποιο εξάμηνο βρίσκεται το οποίο αναθέτουμε στη μεταβλητή 	currentSemester.
	Έπειτα κάνουμε traverse το map enrolledCourses,κάθε φοιτητής μπορεί να κάνει enroll 	σωστά σε μαθήματα του εξαμήνου του ή προηγούμενου(εκτός και αν είναι επι πτυχίω).
	Έπειτα εκτυπώνει τα μαθήματα που έχει κάνει enroll με την βαθμολογία τους και 	στο 	τέλος εκτυπώνει πόσα μαθήματα πέρασε και πόσα μαθήματα έδωσε.

19)studentStatisticsGeneral:
	αρχικά ελέγχει ό,τι ο μαθητής έχει περάσει κάποιο μάθημα κάνοντας iterate τον πίνακα 	passedCourses.
	Εφόσον έχει περάσει κάποιο μάθημα εκτυπώνει τη βαθμολογία του,καθώς και πόσα 	μαθήματα έχει περάσει συνολικά και τον γενικό μέσο όρο του.

20)printStudentsCompleted:
	έχουμε τις static int ectsCount και static int mandatoryCourses
	στην συνάρτηση gradeStudent όταν ο καθητής περνάει έναν φοιτητή τότε αυξάνεται ο 	αριθμός των ects του φοιτητή με τον αριθμό ects του μαθήματος και εάν το μάθημα 	είναι υποχρεωτικό τότε αυξάνεται και η μεταβλητή mandatoryCourses.

	Φοιτητής παίρνει πτυχίο εάν έχει μαζέψει 50ects και έαν έχουν τιμή 5 τα 	υποχρεωτικά μαθήματα που σημαίνει ότι τα έχει περάσει όλα.





 