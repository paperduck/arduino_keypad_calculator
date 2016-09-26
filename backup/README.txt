

Calculator project using: 
	- Arduino Uno and breadboard
	- Ceeco 700-050 12-key numeric keypad
	- Arudino LCD screen

Date:	September 2014

===

Features:
	- Asterisk button cycles through arithmetic operators.
	- Pound sign performs operation.
	- LED turns on when keypad is connected to breadboard.

===

Contents of project:

---

Keypad class (C++) that monitors a matrix circuit of x rows and y columns.

Example usage:

	keypad = new Keypad(4, 3, true);
	unsigned short int row_index;
	unsigned short int col_index;
	while(1){
		keypad.Check( row_index, col_index );
		switch( row_index ){
			case 1:
				switch( col_index ){
					case 1:
						// "1" button pressed
					case 2:
						// "2" button pressed
					case 3:
						// "3" button pressed
				}
			case 2:
				switch ( col_index ){
					case 1:
						// "4"  button pressed
					case 2: 
						// "5" button pressed
					case 3:
						// "6" button pressed
				}
			case 3:
				<...>
			<...>
		}
	}

Members:
	numRows
		Number of rows in keypad. Set in constructor.
	numCols (unsigned short int)
		Number of columns in keypad. Set in constructor.
	UseRowInput (boolean)
		If true, voltage is sent into rows and columns are read as output.
		Otherwise, cols are input and rows are output.
	list of row pins
		User is responsible for adding pin numbers to this list.
	list of column pins 
		user is responsible for adding pin numbers to this list.
	rowIndex (unsigned short int)
		1-based row index of current key to check.
	colIndex (unsigned short int)
		1-based column index of current key to check.
Methods:
	Constructor
		Params:
			unsigned short int numRows
			unsigned short int numCols
			bool useRowInput
		Purpose:
			Constructor
		Outline:
			Set numRows to value passed in
			Set numCols to value passed in
			Set useRowInput to value passed in
			Set rowIndex = 1
			Set colIndex = 1
	private Check
		Params:
			(output) unsigned short int & rowIndex
				Row index (1-based) of key pressed, if any
			(output) unsigned short int & colIndex
				Column index (1-based) of key pressed, if any
		Purpose:
			Check if the current key is pressed and returns its index.
			The program that uses this class is responsible for calling this function over and over,
			to continuously scan the keyspad.
		Returns:
			bool
				false if no key pressed
				true if any key pressed
		Outline:
			If (UseRowInput){
				Turn voltage on to pin with number RowPins[rowIndex]
				Read voltage on ColPins[colIndex]
			}else{
				reverse inputs & outputs
			}
			Increment key indexes.
	private IncrementKeyIterators
		Params:
			none
		Returns:
			void
		Purpose:
			Attempts to increase row index by one. If at max, reset to 1 and increment column index.
			If column index is also at max, reset both indexes to 1.
	public AddRowPin
		Params:
			hex pin name (e.g. A0, 4, 0, etc.)
			bool isAnalog
		Return:
			void
		Purpose:
			Create a new pin struct and add it to the list of row pins.
		Outline:
			Create new pin struct using arguments passed in.
			Add this struct to the existing list of row pins.
	public AddColPin
		Params:
			hex pin name (e.g. A0, 4, 0, etc.)
			bool isAnalog
		Return:
			void
		Purpose:
			Create a new pin struct and add it to the list of column pins.
		Outline:
			Create new pin struct using arguments passed in.
			Add this struct to the existing list of column pins.

---

Struct that contains information about each pin

Members:
	hex pin name (e.g. A0)
	bool isAnalog
	bool isRow

---

Main program

setup()
	Set pins as output/input for hardware as needed
	Create calculator class instance
	Create keypad class instance
	Configure keypad class to use pins that have been wired
loop()
	Uses keypad class above to get keypresses
	Feed keypress data into calculator class
	Send calculator class output to LCD screen.

---

Calculator class

Purpose:
	Takes in keystrokes and outputs a string to display
	Functions as a simple calculator that takes a maximum of two operands and one operator.
	Several operands can be entered, stringed together, but will be processed as soon as
	a pair is entered, left-to-right, with
	no order or operations. 
Members:
	text to show on-screen (string)
	operator (enum?)
		+
		-
		*
		/
		none
	operand 1 (float)
	operand 2 (float)
	operand 1 exists (bool)
	status (unsigned short int???)
		- Editing first operand
		- Editing additional operand
		- Editing operator
		- Just performed calculation
Methods:
	Constructor
		Return:
			N/A
		Params:
			None
		Summary:
			Set "screen text" = ""
			Set operand 1 to 0
			Set operand 2 to 0
			Set operator to [none]
			Print operand 2 to screen
	GetOutput
		Return:
			string that holds text to show on-screen
		Params:
			None
		Purpose:
			Call this function to get the text to show on-screen.
		Outline:
			Just return the internal string.
	Btn_0
	Btn_1
	<...>
	Btn_9
		Returns:
		Params:
		Outline:
			operand 2 = (operand_2 * 10) + 9
			print operand 2
	Btn_Cycle_Operator
		Return:
		Params:
		Outline:
			
			if [operator != none]
				Set operand 1 = (operand 1 [operator] operand 2)
			else
				Set operand 1 = operand 2
			Set operator to whatever default 
			Print operator to screen
			(Subsequent presses will cycle through other operators.)
			(Set operator to next in loop, print to screen)
	public Btn_Equals
		Return:
			void
		Params:
			None
		Outline:
			if [operator != none]
				Set operand 1 = (operand 1 [operator] operand 2)
			else
				operand 1 = operand 2
				[operand 1 exists] = true
			Print operand 1
			

