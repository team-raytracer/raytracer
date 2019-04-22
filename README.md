# Project II: Ray Tracing Engine

## CSCI 155 Computer Graphics, Spring 2019

### Purpose

This project brings together many of the ray tracing topics we have covered and are about to cover. It builds an extendable ray tracing engine by using principles of Object Oriented design. The included ray tracing features are

- tracing a ray through a scene
- ray-primitive intersections
- acceleration structures
- BRDF's and materials for shading and appearance
- scene sampling for anti-aliasing
- any others you may want to include

### The Problem Set

The problems are defined in `main.tex` which is to be compiled using a LaTeX compiler.

### Grading

The marks for this assignment are shown in `rubric.csv`.

### Submission

There are 2 parts to the submission, both due by __10 p.m. on Wednesday, May 8th__.

#### 1. Team Submission: Problem Set

Submit _all_ code files in the `raytracer` folder. `World.cpp` should include an implementation of `World::build` corresponding to the low-res version of your showcase scene. Other `World::build` implementations (e.g. for the high-res version, or used to generate other pictures on your web page) should be included in the `build` folder. Compiling and running `raytracer.cpp` in the `raytracer` folder should generate the low-res image.

Submit a `website` folder that includes your website, either as HTML or as markdown. If the website is additionally hosted online, a URL may be included in the page. the submitted web page must be complete, i.e. all required assets are submitted and no links are broken.

#### 2. Individual Submission: Feedback Form
Every student has to submit feedback on the project at [`Sakai -> Tests & Quizzes`](https://sakai.claremont.edu/x/u9zokH). Note that this is due at the same time as the team submission above so it is recommended to submit it a couple of hours before the deadline.

### Bonus

The engine can be extended ad infinitum. Below are some recommendations but these need not limit you.

- adding interesting materials
- adding texturing
- adding optical effects
- adding a variety of acceleration structures
- implementing parallelization
- adding sophisticated ray tracers

Remember to conspicuously mention additional work on your web page in order to qualify for a bonus.

### Discussion

There is a lot to handle and there are bound to be confusions and queries, not least because of possible errors in the write up or in the provided code. Please be proactive in discussing your problems or seeking clarification using the following avenues.

- discuss with your teammates
- post in the [class forum](https://workplace.facebook.com/groups/354167592088891/)
- talk to me in my office hours
- talk to me after class
