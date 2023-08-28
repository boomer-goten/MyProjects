#include <cairo.h>
#include <gtk/gtk.h>

#include "s21_calc.h"

#define ZOOM_X 200.0
#define ZOOM_Y 200.0

// Calculator
GtkTextBuffer* buffer_input = NULL;
GtkTextBuffer* buffer_output = NULL;
GtkTextBuffer* buffer_x = NULL;
GtkWidget* window_two = NULL;
GtkWidget* window_three = NULL;
GtkWidget* window_four = NULL;

// Credit
GtkTextBuffer* buffer_sum_credit = NULL;
GtkTextBuffer* buffer_srok_credit = NULL;
GtkTextBuffer* buffer_procent_credit = NULL;
GtkTextBuffer* buffer_month_credit = NULL;
GtkTextBuffer* buffer_pereplata_credit = NULL;
GtkTextBuffer* buffer_dolg_credit = NULL;
GtkRadioButton* differ = NULL;

// deposit

GtkTextBuffer* buffer_sum_deposit = NULL;
GtkTextBuffer* buffer_srok_deposit = NULL;
GtkTextBuffer* buffer_date_begin = NULL;
GtkTextBuffer* buffer_proc_deposit = NULL;
GtkTextBuffer* buffer_nalog_deposit = NULL;
GtkComboBoxText* period = NULL;
GtkRadioButton* kapital = NULL;
GtkComboBoxText* popolneniya = NULL;
GtkTextBuffer* buffer_popol_mes = NULL;
GtkTextBuffer* buffer_sum_popol = NULL;
GtkComboBoxText* snyatiya = NULL;
GtkTextBuffer* buffer_snyatiya_mes = NULL;
GtkTextBuffer* buffer_snyatiya_sum = NULL;
GtkTextBuffer* buffer_nachisl_proc_deposit = NULL;
GtkTextBuffer* buffer_sum_nalog_deposit = NULL;
GtkTextBuffer* buffer_sum_result_deposit = NULL;

// graph
GtkTextBuffer* buffer_mashtab = NULL;
GtkWidget* da = NULL;

int mashtab = 5;

gdouble f(gdouble x) {
  GtkTextIter start, end;
  gtk_text_buffer_get_bounds(buffer_input, &start, &end);
  char str_x[40];
  sprintf(str_x, "%lf", x);
  if (strchr(str_x, ',')) {
    char* tmp = strchr(str_x, ',');
    *tmp = '.';
  }
  double result = 0;
  char* expression = gtk_text_buffer_get_text(buffer_input, &start, &end, TRUE);
  int status = OK;
  int size_expr = strlen(expression);
  if (size_expr > 255) {
    char* result_char = "the number of characters must be less than 256";
    gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
  } else {
    status = parser_of_expression(expression, str_x, &result);
    if (status == OK) {
    } else if (status == X) {
      result = 0;
      char* result_char = "x is empty";
      gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
    } else {
      result = 0;
      char* result_char = "BAD EXPRESSION";
      gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
    }
  }
  if (isnan(result) != 0 || isinf(result) != 0) {
    result = 0;
  }
  return result;
}

static gboolean on_draw(GtkWidget* window_four, cairo_t* cr) {
  GdkRectangle da = {0}; /* GtkDrawingArea размер */
  gdouble dx = 5.0, dy = 5.0; /* пикселей между каждой точкой */
  gdouble i = 0.0, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
  GdkWindow* window = gtk_widget_get_window(window_four);
  char buf[30] = "\0";

  /* Определение размеров GtkDrawingArea */
  gdk_window_get_geometry(window, &da.x, &da.y, &da.width, &da.height);

  /* Рисовать на белом фоне */
  cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
  cairo_paint(cr);

  /* Изменить матрицу преобразования */
  cairo_translate(cr, da.width / 2, da.height / 2);
  cairo_scale(cr, ZOOM_X, -ZOOM_Y);

  /* Определите точки данных для расчета (т. е. те, которые находятся в зоне
   * отсечения). */
  cairo_device_to_user_distance(cr, &dx, &dy);
  cairo_clip_extents(cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
  cairo_set_line_width(cr, dx);

  /* Рисует оси x и y */
  cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
  cairo_move_to(cr, clip_x1, 0.0);
  cairo_line_to(cr, clip_x2, 0.0);
  cairo_move_to(cr, 0.0, clip_y1);
  cairo_line_to(cr, 0.0, clip_y2);
  cairo_stroke(cr);

  gdouble j = 0;
  cairo_font_options_t* font_options = NULL;
  cairo_matrix_t ctm = {0}, font_matrix = {0};
  cairo_scaled_font_t* scaled_font = NULL;
  cairo_font_face_t* font_face = cairo_get_font_face(cr);
  font_options = cairo_font_options_create();
  cairo_get_matrix(cr, &ctm);
  cairo_get_font_matrix(cr, &font_matrix);
  font_matrix.xx = 20 / (ZOOM_X + ZOOM_Y);  // font size
  font_matrix.yy = -(20 / (ZOOM_X + ZOOM_Y));
  // font_face initialized elsewhere and is valid
  scaled_font =
      cairo_scaled_font_create(font_face, &font_matrix, &ctm, font_options);
  cairo_set_scaled_font(cr, scaled_font);
  int delta = 0;
  // Прорисовка от 0 до y1
  for (j = -0.40, delta = -2; j > clip_y1; j -= 0.40, delta -= 2) {
    //   // задаем черный цвет
    cairo_set_line_width(cr, 0.005);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_move_to(cr, 0.04, j);
    cairo_line_to(cr, -0.04, j);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0, 0.5, 0);
    cairo_move_to(cr, clip_x2, j);
    cairo_line_to(cr, clip_x1, j);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    sprintf(buf, "%i", delta);
    // рисуем текст метки в нужной точке
    cairo_move_to(cr, 0.05, j + 0.02);
    cairo_show_text(cr, buf);
  }
  // Прорисовка от 0 до y2
  for (j = 0, delta = 0; j < clip_y2; j += 0.40, delta += 2) {
    // задаем черный цвет
    cairo_set_line_width(cr, 0.003);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_move_to(cr, 0.04, j);
    cairo_line_to(cr, -0.04, j);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0, 0.5, 0);
    cairo_move_to(cr, clip_x2, j);
    cairo_line_to(cr, clip_x1, j);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    sprintf(buf, "%i", delta);
    // рисуем текст метки в нужной точке
    cairo_move_to(cr, 0.05, j + 0.02);
    cairo_show_text(cr, buf);
  }
  // Прорисовка от 0 до x1
  for (j = -0.4, delta = -2; j > clip_x1; j -= 0.4, delta -= 2) {
    //   // задаем черный цвет
    cairo_set_line_width(cr, 0.003);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_move_to(cr, j, 0.04);
    cairo_line_to(cr, j, -0.04);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0, 0.5, 0);
    cairo_move_to(cr, j, clip_y2);
    cairo_line_to(cr, j, clip_y1);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    sprintf(buf, "%i", delta);
    // cairo_set_font_size(cr, 0.05);
    // рисуем текст метки в нужной точке
    cairo_move_to(cr, j, -0.1);
    cairo_show_text(cr, buf);
  }
  // Прорисовка от 0 до x2
  for (j = 0.4, delta = 2; j < clip_x2; j += 0.4, delta += 2) {
    // задаем черный цвет
    cairo_set_line_width(cr, 0.003);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_move_to(cr, j, 0.04);
    cairo_line_to(cr, j, -0.04);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0, 0.5, 0);
    cairo_move_to(cr, j, clip_y2);
    cairo_line_to(cr, j, clip_y1);
    cairo_stroke(cr);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    sprintf(buf, "%i", delta);
    // рисуем текст метки в нужной точке
    cairo_move_to(cr, j, -0.1);
    cairo_show_text(cr, buf);
    cairo_stroke(cr);
  }
  font_matrix.xx = 50 / (ZOOM_X + ZOOM_Y);  // font size
  font_matrix.yy = -(50 / (ZOOM_X + ZOOM_Y));
  // font_face initialized elsewhere and is valid
  scaled_font =
      cairo_scaled_font_create(font_face, &font_matrix, &ctm, font_options);
  cairo_set_scaled_font(cr, scaled_font);
  // Прорисовка стрелочек и подпись оси y
  cairo_set_line_width(cr, 0.025);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_move_to(cr, 0, clip_y2);
  cairo_line_to(cr, 0.04, clip_y2 - 0.08);
  cairo_move_to(cr, 0, clip_y2);
  cairo_line_to(cr, -0.04, clip_y2 - 0.08);
  cairo_stroke(cr);
  sprintf(buf, "%s", "Y");
  cairo_move_to(cr, 0.05, clip_y2 - 0.1);
  cairo_show_text(cr, buf);
  cairo_stroke(cr);
  // Прорисовка стрелочек и подпись оси x
  cairo_set_line_width(cr, 0.025);
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_move_to(cr, clip_x2, 0);
  cairo_line_to(cr, clip_x2 - 0.08, 0.04);
  cairo_move_to(cr, clip_x2, 0);
  cairo_line_to(cr, clip_x2 - 0.08, -0.04);
  cairo_stroke(cr);
  sprintf(buf, "%s", "X");
  cairo_move_to(cr, clip_x2 - 0.1, 0.05);
  cairo_show_text(cr, buf);
  cairo_stroke(cr);

  /* Свяжите каждую точку данных */
  cairo_set_line_width(cr, 12 / (ZOOM_X + ZOOM_Y));
  for (i = clip_x1; i < clip_x2; i += (dx / 2))
    cairo_line_to(cr, i, (f(mashtab * i) / mashtab));

  /* Нарисуйте кривую */
  cairo_set_source_rgba(cr, 1, 0.2, 0.2, 0.6);
  cairo_stroke(cr);

  return FALSE;
}

int main(int argc, char* argv[]) {
  gtk_init(&argc, &argv);

  GError* err = NULL;
  GtkBuilder* ui_builder = gtk_builder_new();
  if (!gtk_builder_add_from_file(ui_builder, "./1.glade", &err)) {
    g_critical("Не вышло загрузить файл с UI : %s", err->message);
    g_error_free(err);
  }
  // Инициализация окон
  GtkWidget* window =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "Main_Window"));
  g_signal_connect(window, "destroy", gtk_main_quit, NULL);
  window_two = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Credit"));
  window_three = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Deposit"));
  window_four = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Graph"));

  gtk_builder_connect_signals(ui_builder, NULL);
  // Вызов текстовых виджетов для дефолтного калькулятора
  GtkWidget* Input = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Input"));
  buffer_input = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Input));
  GtkWidget* Output = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Output"));
  buffer_output = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Output));
  GtkWidget* buf_x = GTK_WIDGET(gtk_builder_get_object(ui_builder, "x_string"));
  buffer_x = gtk_text_view_get_buffer(GTK_TEXT_VIEW(buf_x));

  // Вызов виджетов для кредитного калькулятора
  GtkWidget* sum_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "sum_credit"));
  buffer_sum_credit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(sum_credit));
  GtkWidget* srok_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "srok_credit"));
  buffer_srok_credit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(srok_credit));
  GtkWidget* proc_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "proc_credit"));
  buffer_procent_credit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(proc_credit));
  GtkWidget* plata_month_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "plata_month_credit"));
  buffer_month_credit =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(plata_month_credit));
  GtkWidget* pereplata_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "pereplata_credit"));
  buffer_pereplata_credit =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(pereplata_credit));
  GtkWidget* dolg_credit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "dolg_credit"));
  buffer_dolg_credit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(dolg_credit));
  differ = GTK_RADIO_BUTTON(gtk_builder_get_object(ui_builder, "Diff"));

  // Вызов виджетов для депозитного калькулятора
  GtkWidget* sum_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "sum_deposit"));
  buffer_sum_deposit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(sum_deposit));
  GtkWidget* srok_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "srok_deposit"));
  buffer_srok_deposit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(srok_deposit));
  GtkWidget* date_begin =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "date_begin"));
  buffer_date_begin = gtk_text_view_get_buffer(GTK_TEXT_VIEW(date_begin));
  GtkWidget* proc_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "proc_deposit"));
  buffer_proc_deposit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(proc_deposit));
  GtkWidget* nalog_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "nalog_deposit"));
  buffer_nalog_deposit = gtk_text_view_get_buffer(GTK_TEXT_VIEW(nalog_deposit));
  period = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(ui_builder, "combotext3"));
  kapital = GTK_RADIO_BUTTON(gtk_builder_get_object(ui_builder, "no_deposit"));
  popolneniya =
      GTK_COMBO_BOX_TEXT(gtk_builder_get_object(ui_builder, "combotext1"));
  GtkWidget* popol_mes_txt =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "popol_mes_txt"));
  buffer_popol_mes = gtk_text_view_get_buffer(GTK_TEXT_VIEW(popol_mes_txt));
  GtkWidget* suma_popol_txt =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "suma_popol_txt"));
  buffer_sum_popol = gtk_text_view_get_buffer(GTK_TEXT_VIEW(suma_popol_txt));
  snyatiya =
      GTK_COMBO_BOX_TEXT(gtk_builder_get_object(ui_builder, "combotext2"));
  GtkWidget* popol_snyatiya_mes_txt =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "popol_snyatiya_mes_txt"));
  buffer_snyatiya_mes =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(popol_snyatiya_mes_txt));
  GtkWidget* suma_snyatiya_txt =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "suma_snyatiya_txt"));
  buffer_snyatiya_sum =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(suma_snyatiya_txt));
  GtkWidget* sum_proc_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "sum_proc_deposit"));
  buffer_nachisl_proc_deposit =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(sum_proc_deposit));
  GtkWidget* sum_nalog_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "sum_nalog_deposit"));
  buffer_sum_nalog_deposit =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(sum_nalog_deposit));
  GtkWidget* sum_result_deposit =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "sum_result_deposit"));
  buffer_sum_result_deposit =
      gtk_text_view_get_buffer(GTK_TEXT_VIEW(sum_result_deposit));

  // Вызов виджетов для графика
  da = GTK_WIDGET(gtk_builder_get_object(ui_builder, "Graphic"));
  GtkWidget* mashtab_value =
      GTK_WIDGET(gtk_builder_get_object(ui_builder, "Mashtab_value"));
  buffer_mashtab = gtk_text_view_get_buffer(GTK_TEXT_VIEW(mashtab_value));
  g_signal_connect(G_OBJECT(da), "draw", G_CALLBACK(on_draw), NULL);

  gtk_widget_show(window);
  gtk_main();
  g_object_unref(ui_builder);
  return 0;
}

G_MODULE_EXPORT void on_btn_sk1_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "(", 1);
}

G_MODULE_EXPORT void on_btn_sk2_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), ")", 1);
}

G_MODULE_EXPORT void on_btn_one_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "1", 1);
}

G_MODULE_EXPORT void on_btn_two_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "2", 1);
}

G_MODULE_EXPORT void on_btn_three_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "3", 1);
}

G_MODULE_EXPORT void on_btn_four_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "4", 1);
}

G_MODULE_EXPORT void on_btn_five_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "5", 1);
}

G_MODULE_EXPORT void on_btn_six_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "6", 1);
}

G_MODULE_EXPORT void on_btn_seven_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "7", 1);
}

G_MODULE_EXPORT void on_btn_eight_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "8", 1);
}

G_MODULE_EXPORT void on_btn_nine_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "9", 1);
}

G_MODULE_EXPORT void on_btn_zero_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "0", 1);
}

G_MODULE_EXPORT void on_btn_tochka_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), ".", 1);
}

G_MODULE_EXPORT void on_btn_mod_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "mod", 3);
}

G_MODULE_EXPORT void on_btn_plus_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "+", 1);
}

G_MODULE_EXPORT void on_btn_minus_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "-", 1);
}

G_MODULE_EXPORT void on_btn_umnoj_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "*", 1);
}

G_MODULE_EXPORT void on_btn_del_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "/", 1);
}

G_MODULE_EXPORT void on_btn_step_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "^", 1);
}

G_MODULE_EXPORT void on_btn_cos_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "cos()", 5);
}

G_MODULE_EXPORT void on_btn_sin_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "sin()", 5);
}

G_MODULE_EXPORT void on_btn_tan_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "tan()", 5);
}

G_MODULE_EXPORT void on_btn_ln_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "ln()", 4);
}

G_MODULE_EXPORT void on_btn_sqrt_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "sqrt()", 6);
}

G_MODULE_EXPORT void on_btn_acos_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "acos()", 6);
}

G_MODULE_EXPORT void on_btn_asin_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "asin()", 6);
}

G_MODULE_EXPORT void on_btn_log_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "log()", 5);
}

G_MODULE_EXPORT void on_btn_atan_clicked() {
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(buffer_input), "atan()", 6);
}

G_MODULE_EXPORT void on_btn_plus_mash_clicked() {
  if (mashtab <= 5000000) {
    mashtab *= 10;
    GtkTextIter start_mash, end_mash;
    gtk_text_buffer_get_bounds(buffer_mashtab, &start_mash, &end_mash);
    gtk_text_buffer_delete(buffer_mashtab, &start_mash, &end_mash);
    char bufff[40] = "\0";
    sprintf(bufff, "1:%d", mashtab / 5);
    gtk_text_buffer_set_text(buffer_mashtab, bufff, strlen(bufff));
  }
}

G_MODULE_EXPORT void on_btn_minus_mash_clicked() {
  if (mashtab > 5) {
    mashtab /= 10;
    GtkTextIter start_mash_min, end_mash_min;
    gtk_text_buffer_get_bounds(buffer_mashtab, &start_mash_min, &end_mash_min);
    gtk_text_buffer_delete(buffer_mashtab, &start_mash_min, &end_mash_min);
    char bufff[40] = "\0";
    sprintf(bufff, "1:%d", mashtab / 5);
    gtk_text_buffer_set_text(buffer_mashtab, bufff, strlen(bufff));
  }
}

G_MODULE_EXPORT void on_btn_credit_clicked() { gtk_widget_show(window_two); }

G_MODULE_EXPORT void on_btn_deposit_clicked() { gtk_widget_show(window_three); }

G_MODULE_EXPORT void on_btn_graph_clicked() { gtk_widget_show(window_four); }

G_MODULE_EXPORT void on_btn_res_credit_clicked() {
  GtkTextIter start_1, end_1;
  GtkTextIter start_2, end_2;
  GtkTextIter start_3, end_3;
  gtk_text_buffer_get_bounds(buffer_sum_credit, &start_1, &end_1);
  gtk_text_buffer_get_bounds(buffer_srok_credit, &start_2, &end_2);
  gtk_text_buffer_get_bounds(buffer_procent_credit, &start_3, &end_3);
  char* summ =
      gtk_text_buffer_get_text(buffer_sum_credit, &start_1, &end_1, TRUE);
  char* srok =
      gtk_text_buffer_get_text(buffer_srok_credit, &start_2, &end_2, TRUE);
  char* proc_stavka =
      gtk_text_buffer_get_text(buffer_procent_credit, &start_3, &end_3, TRUE);
  int type = 0;
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(differ))) {
    type = 1;
  }
  double result_sum = 0;
  double result_proc = 0;
  char result_platezh[100] = "\0";
  memset(result_platezh, '\0', 100);
  int status = OK;
  int size_sum = strlen(summ);
  int size_srok = strlen(srok);
  int size_procent = strlen(proc_stavka);
  if (size_sum > 32 || size_srok > 32 || size_procent > 32) {
    char* result_platezh = "too many characters";
    char* result_proc_str = "too many characters";
    char* result_sum_str = "too many characters";
    gtk_text_buffer_set_text(buffer_month_credit, result_platezh,
                             strlen(result_platezh));
    gtk_text_buffer_set_text(buffer_pereplata_credit, result_proc_str,
                             strlen(result_proc_str));
    gtk_text_buffer_set_text(buffer_dolg_credit, result_sum_str,
                             strlen(result_sum_str));
  } else {
    status = credit(summ, srok, proc_stavka, &type, result_platezh,
                    &result_proc, &result_sum);
    if (status == OK) {
      char result_proc_str[100] = "\0";
      char result_sum_str[100] = "\0";
      memset(result_proc_str, '\0', 100);
      memset(result_sum_str, '\0', 100);
      sprintf(result_proc_str, "%lf", result_proc);
      sprintf(result_sum_str, "%lf", result_sum);
      gtk_text_buffer_set_text(buffer_month_credit, result_platezh,
                               strlen(result_platezh));
      gtk_text_buffer_set_text(buffer_pereplata_credit, result_proc_str,
                               strlen(result_proc_str));
      gtk_text_buffer_set_text(buffer_dolg_credit, result_sum_str,
                               strlen(result_sum_str));
    } else {
      char* result_platezh = "Error";
      char* result_proc_str = "Error";
      char* result_sum_str = "Error";
      gtk_text_buffer_set_text(buffer_month_credit, result_platezh,
                               strlen(result_platezh));
      gtk_text_buffer_set_text(buffer_pereplata_credit, result_proc_str,
                               strlen(result_proc_str));
      gtk_text_buffer_set_text(buffer_dolg_credit, result_sum_str,
                               strlen(result_sum_str));
    }
  }
}

G_MODULE_EXPORT void on_window2_delete_event() {
  gtk_widget_hide_on_delete(window_two);
}

G_MODULE_EXPORT void on_window3_delete_event() {
  gtk_widget_hide_on_delete(window_three);
}

G_MODULE_EXPORT void on_window4_delete_event() {
  gtk_widget_hide_on_delete(window_four);
}

G_MODULE_EXPORT void on_btn_delete_clicked() {
  GtkTextIter start, end;
  GtkTextIter start_out, end_out;
  GtkTextIter start_x, end_x;
  gtk_text_buffer_get_bounds(buffer_input, &start, &end);
  gtk_text_buffer_get_bounds(buffer_output, &start_out, &end_out);
  gtk_text_buffer_get_bounds(buffer_x, &start_x, &end_x);
  gtk_text_buffer_delete(buffer_input, &start, &end);
  gtk_text_buffer_delete(buffer_output, &start_out, &end_out);
  gtk_text_buffer_delete(buffer_x, &start_x, &end_x);
  char* preview = "0";
  gtk_text_buffer_set_text(buffer_output, preview, strlen(preview));
  gtk_text_buffer_set_text(buffer_x, preview, strlen(preview));
}

G_MODULE_EXPORT void on_btn_result_clicked() {
  GtkTextIter start, end;
  GtkTextIter start_x, end_x;
  gtk_text_buffer_get_bounds(buffer_input, &start, &end);
  gtk_text_buffer_get_bounds(buffer_x, &start_x, &end_x);
  double result = 0;
  char* expression = gtk_text_buffer_get_text(buffer_input, &start, &end, TRUE);
  char* x = gtk_text_buffer_get_text(buffer_x, &start_x, &end_x, TRUE);
  int status = OK;
  int size_expr = strlen(expression);
  if (size_expr > 255) {
    char* result_char = "the number of characters must be less than 256";
    gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
  } else {
    status = parser_of_expression(expression, x, &result);
    if (status == OK) {
      char result_char[100] = "\0";
      memset(result_char, '\0', 100);
      sprintf(result_char, "%lf", result);
      gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
    } else if (status == X) {
      char* result_char = "x is empty";
      gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
    } else {
      char* result_char = "BAD EXPRESSION";
      gtk_text_buffer_set_text(buffer_output, result_char, strlen(result_char));
    }
  }
}

G_MODULE_EXPORT void on_btn_res_deposit_clicked() {
  GtkTextIter start_dep_1, end_dep_1;
  GtkTextIter start_dep_2, end_dep_2;
  GtkTextIter start_dep_3, end_dep_3;
  GtkTextIter start_dep_4, end_dep_4;
  GtkTextIter start_dep_5, end_dep_5;
  GtkTextIter start_dep_6, end_dep_6;
  GtkTextIter start_dep_7, end_dep_7;
  GtkTextIter start_dep_8, end_dep_8;
  GtkTextIter start_dep_9, end_dep_9;
  gtk_text_buffer_get_bounds(buffer_sum_deposit, &start_dep_1, &end_dep_1);
  gtk_text_buffer_get_bounds(buffer_srok_deposit, &start_dep_2, &end_dep_2);
  gtk_text_buffer_get_bounds(buffer_date_begin, &start_dep_5, &end_dep_5);
  gtk_text_buffer_get_bounds(buffer_proc_deposit, &start_dep_3, &end_dep_3);
  gtk_text_buffer_get_bounds(buffer_nalog_deposit, &start_dep_4, &end_dep_4);
  gtk_text_buffer_get_bounds(buffer_popol_mes, &start_dep_6, &end_dep_6);
  gtk_text_buffer_get_bounds(buffer_sum_popol, &start_dep_7, &end_dep_7);
  gtk_text_buffer_get_bounds(buffer_snyatiya_mes, &start_dep_8, &end_dep_8);
  gtk_text_buffer_get_bounds(buffer_snyatiya_sum, &start_dep_9, &end_dep_9);
  char* sum_dep = gtk_text_buffer_get_text(buffer_sum_deposit, &start_dep_1,
                                           &end_dep_1, TRUE);
  char* srok_dep = gtk_text_buffer_get_text(buffer_srok_deposit, &start_dep_2,
                                            &end_dep_2, TRUE);
  char* date_dep = gtk_text_buffer_get_text(buffer_date_begin, &start_dep_5,
                                            &end_dep_5, TRUE);
  char* proc_dep = gtk_text_buffer_get_text(buffer_proc_deposit, &start_dep_3,
                                            &end_dep_3, TRUE);
  char* nalog_dep = gtk_text_buffer_get_text(buffer_nalog_deposit, &start_dep_4,
                                             &end_dep_4, TRUE);
  char* popol_mes_dep = gtk_text_buffer_get_text(buffer_popol_mes, &start_dep_6,
                                                 &end_dep_6, TRUE);
  char* sum_popol_dep = gtk_text_buffer_get_text(buffer_sum_popol, &start_dep_7,
                                                 &end_dep_7, TRUE);
  char* snyatiya_mes_dep = gtk_text_buffer_get_text(
      buffer_snyatiya_mes, &start_dep_8, &end_dep_8, TRUE);
  char* snyatiya_sum_dep = gtk_text_buffer_get_text(
      buffer_snyatiya_sum, &start_dep_9, &end_dep_9, TRUE);
  char* spisok_popol_dep = gtk_combo_box_text_get_active_text(popolneniya);
  char* spisok_snyatiya_dep = gtk_combo_box_text_get_active_text(snyatiya);
  char* spisok_period_dep = gtk_combo_box_text_get_active_text(period);
  int type = 1;
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(kapital))) {
    type = 0;
  }
  double result_procent = 0;
  double result_nalog = 0;
  double result_deposit = 0;
  int status = OK;
  if (strlen(sum_dep) > 50 || strlen(srok_dep) > 50 || strlen(proc_dep) > 50 ||
      strlen(nalog_dep) > 50 || strlen(popol_mes_dep) > 50 ||
      strlen(sum_popol_dep) > 50 || strlen(snyatiya_mes_dep) > 50 ||
      strlen(snyatiya_sum_dep) > 50) {
    char* result_procent_str = "too many characters";
    char* result_nalog_str = "too many characters";
    char* result_deposit_str = "too many characters";
    gtk_text_buffer_set_text(buffer_nachisl_proc_deposit, result_procent_str,
                             strlen(result_procent_str));
    gtk_text_buffer_set_text(buffer_sum_nalog_deposit, result_nalog_str,
                             strlen(result_nalog_str));
    gtk_text_buffer_set_text(buffer_sum_result_deposit, result_deposit_str,
                             strlen(result_deposit_str));
  } else {
    status =
        deposit(sum_dep, srok_dep, date_dep, proc_dep, nalog_dep, popol_mes_dep,
                sum_popol_dep, snyatiya_mes_dep, snyatiya_sum_dep,
                spisok_popol_dep, spisok_snyatiya_dep, spisok_period_dep, &type,
                &result_procent, &result_nalog, &result_deposit);
    if (status == OK) {
      char result_procent_str[100] = "\0";
      char result_nalog_str[100] = "\0";
      char result_deposit_str[100] = "\0";
      sprintf(result_procent_str, "%lf", result_procent);
      sprintf(result_nalog_str, "%lf", result_nalog);
      sprintf(result_deposit_str, "%lf", result_deposit);
      gtk_text_buffer_set_text(buffer_nachisl_proc_deposit, result_procent_str,
                               strlen(result_procent_str));
      gtk_text_buffer_set_text(buffer_sum_nalog_deposit, result_nalog_str,
                               strlen(result_nalog_str));
      gtk_text_buffer_set_text(buffer_sum_result_deposit, result_deposit_str,
                               strlen(result_deposit_str));
    } else {
      char* result_procent_str = "Error";
      char* result_nalog_str = "Error";
      char* result_deposit_str = "Error";
      gtk_text_buffer_set_text(buffer_nachisl_proc_deposit, result_procent_str,
                               strlen(result_procent_str));
      gtk_text_buffer_set_text(buffer_sum_nalog_deposit, result_nalog_str,
                               strlen(result_nalog_str));
      gtk_text_buffer_set_text(buffer_sum_result_deposit, result_deposit_str,
                               strlen(result_deposit_str));
    }
  }
}
