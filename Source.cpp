#include <GLFW/glfw3.h>
#include<algorithm>

const int width = 840;
const int height = 840;


float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

int main(void)
{
	GLFWwindow* window;



	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(840, 840, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		
		std::fill_n(pixels, width*height * 3, 1.0f);	// background 
															


	//150, 500 | 자
		for (int i = 100; i < 200; i++) {
			for (int j = 450; j < 550; j++) {
				
				double empty_circle;
				empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 500)*((double)j - 500) - 49 * 49;
				
				if ((490<xpos)&& (xpos<510)&&(140<(840-ypos))&&((840-ypos)<160) ) {


					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 500)*((double)j - 500) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) { drawPixel(j, i, 1.0f, 0.0f, 0.0f); 
					for (int i=130;i<170;i++)
						drawPixel(500,i , 1.0f, 0.0f, 0.0f);
					
					}
					
				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 500)*((double)j - 500) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						for (int i = 130; i<170; i++)
							drawPixel(500, i, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}
	//150,700 //라인
		for (int i = 100; i < 200; i++) {
			for (int j = 450; j < 750; j++) {

				double empty_circle;
				empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 700)*((double)j - 700) - 49 * 49;

				if ((690<xpos) && (xpos<710) && (140<(840 - ypos)) && ((840 - ypos)<160)) {


					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 700)*((double)j - 700) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						drawLine(690,140 ,710 ,160 , 1.0f, 0.0f, 0.0f);

					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 700)*((double)j - 700) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						drawLine(690, 140, 710, 160, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}
	//150,300 //원
		for (int i = 100; i < 200; i++) {
			for (int j = 250; j < 350; j++) {

				double empty_circle;
				empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j -300) - 49 * 49;

				if ((290<xpos) && (xpos<310) && (140<(840 - ypos)) && ((840 - ypos)<160)) {


					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						
						for (int i = 120; i < 180; i++) {
							for (int j = 270; j < 330; j++) {
								double empty_circle;
								empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 29 * 29;
								double mouse_circle;
								mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 30 * 30;
								if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
									drawPixel(j, i, 1.0f, 0.0f, 0.0f);
								}
							}
						}

					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						for (int i = 120; i < 180; i++) {
							for (int j = 270; j < 330; j++) {
								double empty_circle;
								empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 29 * 29;
								double mouse_circle;
								mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 300)*((double)j - 300) - 30 * 30;
								if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
									drawPixel(j, i, 1.0f, 0.0f, 0.0f);
								}
							}
						}
					}

				}

			}
		}
	//150,100//네모
		for (int i = 100; i < 200; i++) {
			for (int j = 50; j < 150; j++) {

				double empty_circle;
				empty_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 100)*((double)j - 100) - 49 * 49;

				if ((90<xpos) && (xpos<110) && (140<(840 - ypos)) && ((840 - ypos)<160)) {


					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 100)*((double)j - 100) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);

						//emty square
						for (int i = 120; i<180; i++) {//채워진 네모
							for (int j = 70; j<130; j++) {
								drawPixel(j, i, 1.0f, 0.0f, 0.0f);
							}
						}
						for (int i = 130; i<170; i++) {//빈공간
							for (int j = 80; j<120; j++) {
								drawPixel(j, i, 1.0f, 1.0f, 1.0f);
							}
						}


					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 150)*((double)i - 150) + ((double)j - 100)*((double)j - 100) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);

						//emty square
						for (int i = 120; i<180; i++) {//채워진 네모
							for (int j = 70; j<130; j++) {
								drawPixel(j, i, 1.0f, 0.0f, 0.0f);
							}
						}
						for (int i = 130; i<170; i++) {//빈공간
							for (int j = 80; j<120; j++) {
								drawPixel(j, i, 1.0f, 1.0f, 1.0f);
							}
						}


					}

				}

			}
		}
	//250,100//x자
		for (int i = 200; i < 300; i++) {
			for (int j = 50; j < 150; j++) {

				double empty_circle;
				empty_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 100)*((double)j - 100) - 49 * 49;

				if ((90<xpos) && (xpos<110) && (240<(840 - ypos)) && ((840 - ypos)<260)) {


					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 100)*((double)j - 100) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						drawLine(80, 260, 110, 240, 1.0f, 0.0f, 0.0f);
						drawLine(80, 240, 110, 260, 1.0f, 0.0f, 0.0f);
					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 100)*((double)j - 100) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						drawLine(80, 260, 110, 240, 1.0f, 0.0f, 0.0f);
						drawLine(80, 240, 110, 260, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}
	//250,300 아래방향화살표
		for (int i = 200; i < 300; i++) {
			for (int j = 250; j < 350; j++) {

				double empty_circle;
				empty_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 300)*((double)j - 300) - 49 * 49;

				if ((290<xpos) && (xpos<310) && (240<(840 - ypos)) && ((840 - ypos)<260)) {


					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 300)*((double)j - 300) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						for (int i = 230; i<270; i++)
							drawPixel(300, i, 1.0f, 0.0f, 0.0f);
						drawLine(300, 230,320 , 250 , 1.0f, 0.0f, 0.0f);
						drawLine(280, 250, 300, 230, 1.0f, 0.0f, 0.0f);

					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 300)*((double)j - 300) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						for (int i = 230; i<270; i++)
							drawPixel(300, i, 1.0f, 0.0f, 0.0f);
						drawLine(300, 230, 320, 250, 1.0f, 0.0f, 0.0f);
						drawLine(280, 250, 300, 230, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}
	//250,500 오른쪽 화살표
		for (int i = 200; i < 300; i++) {
			for (int j = 450; j < 550; j++) {

				double empty_circle;
				empty_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 500)*((double)j - 500) - 49 * 49;

				if ((490<xpos) && (xpos<510) && (240<(840 - ypos)) && ((840 - ypos)<260)) {


					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 500)*((double)j - 500) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						for (int i = 470; i<530; i++)
							drawPixel(i, 250, 1.0f, 0.0f, 0.0f);
						drawLine(500, 230, 530, 250, 1.0f, 0.0f, 0.0f);
						drawLine(500, 270, 530, 250, 1.0f, 0.0f, 0.0f);


					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 500)*((double)j - 500) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						for (int i = 470; i<530; i++)
							drawPixel(i, 250, 1.0f, 0.0f, 0.0f);
						drawLine(500, 230, 530, 250, 1.0f, 0.0f, 0.0f);
						drawLine(500, 270, 530, 250, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}
	//250,700 왼쪽방향	화살표

		for (int i = 200; i < 300; i++) {
			for (int j = 650; j < 750; j++) {

				double empty_circle;
				empty_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 700)*((double)j - 700) - 49 * 49;

				if ((690<xpos) && (xpos<710) && (240<(840 - ypos)) && ((840 - ypos)<260)) {


					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 700)*((double)j - 700) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 1.0f, 0.0f, 0.0f);
						for (int i = 670; i<730; i++)
							drawPixel(i, 250, 1.0f, 0.0f, 0.0f);
						drawLine(670, 250, 700, 230, 1.0f, 0.0f, 0.0f);
						drawLine(670, 250, 700, 270, 1.0f, 0.0f, 0.0f);


					}

				}
				else {

					double mouse_circle;
					mouse_circle = ((double)i - 250)*((double)i - 250) + ((double)j - 700)*((double)j - 700) - 50 * 50;

					if ((mouse_circle < 0.0) && (empty_circle>0.0)) {
						drawPixel(j, i, 0.0f, 1.0f, 0.0f);
						for (int i = 670; i<730; i++)
							drawPixel(i, 250, 1.0f, 0.0f, 0.0f);
						drawLine(670, 250, 700, 230, 1.0f, 0.0f, 0.0f);
						drawLine(670, 250, 700, 270, 1.0f, 0.0f, 0.0f);
					}

				}

			}
		}

			glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}