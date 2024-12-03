# Assignment 2

I'm not sure that I needed to implement this, but I did implementations anyway.

I learned the *curiously recurring template pattern* to learn how to make this while minimizing the number of .cpp files
actually needed for the child animals seen by the vets (i.e. Cats, Dogs, etc.). By using this pattern and a static
method
inside the child class definitions I could further minimize the amount of code needed to be implemented.

Not only am I not repeating myself, but it is fewer spots that require changes in the event of a revision.

Through the use of macros, I was able to have the different colour, marking and similar options for the child classes
entered in one spot, where more can easily be added or removed. Changing the macro will automatically add or remove
other lines in the rest of the header files

fter cloning the repository, navigate to the downloaded directory and run:

```bash
make compile
```

*Note:* On FreeBSD you will need to use `gmake` and not the base install `make` for all build, test and documentation
commands on this page

A binary executable will be produced. To start the game simply run the Assign2 executable

```bash
./Assign2
```

## Tests and Documentation

### Quality Checks

### Unit Tests

To build and run unit tests please run the following command:

  ```bash
  make test
  ```

This will automatically build and run the googleTest unit tests for the application.

### Active Tests

To check the application for memory leaks, please run the following command:

  ```bash
  make memcheck-test
  ```

This command will run `valgrind` on the Assing2_test binary produced for unit tests, checking for dynamically
allocated memory that has not been freed

```bash
  valgrind ./Assign2
```

**John spent a butt load of time learning how to use smart pointers, so there are no memory leaks!!**

#### Style Check

The source code adheres the Google C++ coding style.  
To perform a style check on the source code, please run the following command:

  ```bash
  make style
  ```

*Note:* The style check will require the application `cpplint` be installed

#### Static Check

To perform a static analysis of the source code please run the following command

  ```bash
  make static
  ```

*Note:* The static analysis will require that the application `cppcheck` be installed

**John spent all of his time learning the *CRTP* pattern and smart pointers, so he didn't even bother trying adhere to
the proper style checks.
He might have fixed it if he didn't have a final exam later today and work in six hours...**

### Documentation

#### Source Code Documentation

To build documentation for the C++ source code run the following command:

```bash
make docs
```